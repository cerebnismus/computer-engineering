/**
* @file tuketici.c
* @description Yavru işlemi olarak başlatılan üretici işlemin ortak belleğe yazdığı verileri semafordan yararlanarak
 * okur. Semaforun kullanılmasının nedeni okumanın yapılması için üretici işlemin değer yazmasının beklenmesidir.
* @course 2A
* @assignment 1
* @date 11.25.2016
* @authors
 * Emirhan Aydın (g141210018@sakarya.edu.tr)
 * Mesut Sertaç Gün (g141210036@sakarya.edu.tr)
 * Abdullah Bahar (g141210090@sakarya.edu.tr)
*/

#include <fcntl.h>          /* O_CREAT, O_EXEC                          */
#include <unistd.h>         /* fork()                                   */
#include <stdio.h>          /* printf()                                 */
#include <stdlib.h>         /* exit(), malloc(), free()                 */
#include <sys/shm.h>        /* shmat(), IPC_RMID                        */
#include <semaphore.h>      /* sem_open(), sem_destroy(), sem_wait()..  */
#include <signal.h>         /* sig_atomic_t, signal(), kill(), SIGINT   */
#include <stdbool.h>        /* bool, true                               */
#include "kayit.h"          /* struct kayit                             */

#define imleci_tasi(x, y) printf("\033[%d;%dH", (x), (y)) /* İmleci belirtilen konuma taşır. */
#define boyut_degistir(w, h) printf("\e[8;%d;%dt", (h), (w)) /* Terminal boyutunu değiştirir. */
#define aktif_renk(r, g, b) printf("\e[38;2;%d;%d;%dm", (r), (g), (b)) /* Yazı rengini aktif renk için değiştirir. */
#define rengi_sifirla() printf("\e[0m") /* Yazı rengini terminal varsayılanına döndürür. */

int shmid;          /* Ortak bellek kimliği     *//* Paylaşılan */
sem_t *sem;         /* Semafor                  */
pid_t pid;          /* Çocuk işlem kimliği      */
struct kayit *p;    /* Paylaşılan olay kaydı    */

void cikis_sinyali(int s); /* Çıkış için SIGINT sinyalini yakalar ve programı kontrollü olarak sonlandırır. */

void tablo_ciz(); /* Verilerin yazılacağı tablo biçimini ekrana yazdırır. */

int main(int argc, char **argv) {
    int i = 0;                                  /* Döngü değişkenleri       */
    char shmid_buffer[8];                       /* shmid int dönüşümü       */
    const char *semname = "/smpfsyncmech";      /* Semafor adı              *//* Paylaşılan */
    size_t kyt_boyut = sizeof(struct kayit);    /* Olay kaydı yapısı boyutu */
    struct kayit *gez;                          /* Gezilen kaydı gösterir   */
    bool ilk_tur = true;                        /* İlk verinin okunması     */

    /* Minimum boyut olan 1 sayfalık (4096 byte) alan oluşturulur. 10 adet kaydı tutmak için fazlasıyla yeterlidir. */
    shmid = shmget(IPC_PRIVATE, 1, 0644 | IPC_CREAT);

    p = (struct kayit *) shmat(shmid, NULL, 0);   /* p göstericisine paylaşılan belleğin başlangıç adresi atanır. */

    /* İşlemler arası senkronizasyon için semafor oluşturulur. */
    /* Semaforun adı sabit üzerinden tanımlanır, işlemlerden bu isim ile erişim sağlanacaktır. */
    sem = sem_open(semname, O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, 0);

    pid = fork();

    system("clear");

    if (pid == 0) { /* Yavru işlem */
        sprintf(shmid_buffer, "%d", shmid);
        execl("./uretici", shmid_buffer, semname, NULL);
    } else if (pid < 0) { /* Fork hatası */
        perror("Fork isleminde hata meydana geldi.\n");
        exit(1);
    } else { /* Ebeveyn işlem */
        signal(SIGINT, cikis_sinyali); /* Kontrollü bir şekilde çıkış yapmak için SIGINT sinyali yakalanır. */

        while (1) {
            sem_wait(sem); /* Üretici işlemin veri girmesi ve semaforu yükseltmesi beklenir. */

            if (ilk_tur) { /* Okunan ilk veri ise tablo çizilir. */
                imleci_tasi(0, 0);
                tablo_ciz();
                ilk_tur = false;
            } else { /* İlk tur değilse önceki veri varsayılan renge değiştirilir. */
                rengi_sifirla();
                imleci_tasi(2 * (i + 1), 3);
                printf("%-10d\t%5s%-7d\t%3s%d\t\t%p\n", gez->sira, "", gez->veri, "", i - 1, gez);
                if (i > 9) i = 0; /* Dairesel olarak gezmek için olan sayacın değeri 0 ile 9 aralığında tutulur. */
            }

            imleci_tasi(2 * (i + 1) + 2, 3);
            gez = p + kyt_boyut * i; /* Gezici gösterici bir sonraki olay kaydına taşınır. */
            aktif_renk(0, 255, 0); /* Yeni veri ekrana yazılırken yazı rengi aktif renk olarak değiştirilir. */
            printf("%-10d\t%5s%-7d\t%3s%d\t\t%p\n", gez->sira, "", gez->veri, "", i, gez);

            i++;
        }
    }
}

void cikis_sinyali(int s) {
    system("clear");
    system("setterm -cursor on"); /* Terminalde imleç tekrar gösterilir. */
    rengi_sifirla(); /* Terminal rengi varsayılana döndürülür. */

    /* Yavru işlem SIGINT sinyali ile öldürülür. Bu sinyal yavru işlemde yakalanır ve kontrollü sonlandırılır. */
    kill(pid, SIGINT);

    /* Paylaşılan bellek ile bağlantı kesilir. */
    shmdt(p);
    /* Paylaşılan bellek serbest bırakılır. */
    shmctl(shmid, IPC_RMID, 0);

    /* Semafor silinir. */
    sem_destroy(sem);

    printf("\n\nProgram temiz bir sekilde sonlandirilmistir.\n\n");

    exit(EXIT_SUCCESS);
}

void tablo_ciz() {
    boyut_degistir(63, 23); /* Terminal boyutu tabloya uyarlanır. */
    system("setterm -cursor off"); /* Terminalde imlecin gösterilmesi devre dışı bırakılır. */

    printf("┌──────────────┬────────────┬─────────────┬───────────────────┐\n"
                   "│    Kimlik    │    Veri    │    Konum    │       Adres       │\n"
                   "├──────────────┼────────────┼─────────────┼───────────────────┤\n"
                   "│              │            │             │                   │\n"
                   "├──────────────┼────────────┼─────────────┼───────────────────┤\n"
                   "│              │            │             │                   │\n"
                   "├──────────────┼────────────┼─────────────┼───────────────────┤\n"
                   "│              │            │             │                   │\n"
                   "├──────────────┼────────────┼─────────────┼───────────────────┤\n"
                   "│              │            │             │                   │\n"
                   "├──────────────┼────────────┼─────────────┼───────────────────┤\n"
                   "│              │            │             │                   │\n"
                   "├──────────────┼────────────┼─────────────┼───────────────────┤\n"
                   "│              │            │             │                   │\n"
                   "├──────────────┼────────────┼─────────────┼───────────────────┤\n"
                   "│              │            │             │                   │\n"
                   "├──────────────┼────────────┼─────────────┼───────────────────┤\n"
                   "│              │            │             │                   │\n"
                   "├──────────────┼────────────┼─────────────┼───────────────────┤\n"
                   "│              │            │             │                   │\n"
                   "├──────────────┼────────────┼─────────────┼───────────────────┤\n"
                   "│              │            │             │                   │\n"
                   "└──────────────┴────────────┴─────────────┴───────────────────┘"
    );

    /* Tablo başlıkları renklendirilir. */
    aktif_renk(0, 255, 255);
    imleci_tasi(2, 6);
    printf("Kimlik");
    imleci_tasi(2, 21);
    printf("Veri");
    imleci_tasi(2, 34);
    printf("Konum");
    imleci_tasi(2, 51);
    printf("Adres");
}