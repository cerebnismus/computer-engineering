/**
* @file uretici.c
* @description Her saniyede bir ebeveyn işlem ile ortak bellek bölgesine bir veri yazar. Ortak bellek bölgesinin
 * kimliğini ve senkronizasyon için kullanılacak olan semaforun adını komut satırı parametresi olarak alır.
* @course 2A
* @assignment 1
* @date 11.25.2016
* @authors
 * Emirhan Aydın (g141210018@sakarya.edu.tr)
 * Mesut Sertaç Gün (g141210036@sakarya.edu.tr)
 * Abdullah Bahar (g141210090@sakarya.edu.tr)
*/

#include <time.h>           /* time()                                   */
#include <fcntl.h>          /* O_CREAT, O_EXEC                          */
#include <unistd.h>         /* fork()                                   */
#include <stdlib.h>         /* exit(), malloc(), free()                 */
#include <sys/shm.h>        /* shmat(), IPC_RMID                        */
#include <semaphore.h>      /* sem_open(), sem_destroy(), sem_wait()..  */
#include <signal.h>         /* sig_atomic_t, signal(), kill(), SIGINT   */
#include <stdbool.h>        /* bool, true                               */
#include "kayit.h"          /* struct kayit                             */

int shmid;              /* Ortak bellek kimliği                     *//* Paylaşılan */
struct kayit *p;        /* Paylaşılan olay kaydı                    */
sem_t *sem;             /* Semafor                                  */
bool calis = true;      /* Sonsuz döngü uyarısını yok saymak için   */

void kayit_sinyali(int s) {} /* Boş bir sinyal dinleyicisi, uyku durumundan çıkmak için kullanılır. */
void cikis_sinyali(int s); /* Çıkış için SIGINT sinyalini yakalar ve programı kontrollü olarak sonlandırır. */

int main(int argc, char **argv) {
    int i = 0, j = 0;                           /* Döngü değişkenleri       */
    const char *semname = argv[1];              /* Semafor adı              *//* Paylaşılan */
    size_t kyt_boyut = sizeof(struct kayit);    /* Olay kaydı yapısı boyutu */
    struct kayit *gez;                          /* Gezilen kaydı gösterir   */

    shmid = atoi(argv[0]); /* Paylaşılan bellek kimliği komut satırı parametresi olarak alınır. */

    p = (struct kayit *) shmat(shmid, NULL, O_RDWR); /* p göstericisine paylaşılan belleğin başlangıç adresi atanır. */

    sem = sem_open(semname, 0); /* Önceden oluşturulmuş ve adı parametre ile gelen semafor göstericiye atanır. */
    /* Semafor adının sistemle bağlantısı kesilir. Böylece sistemde bu isimde başka bir semafor oluşturulabilir. */
    sem_unlink(semname);

    signal(SIGALRM, kayit_sinyali); /* Her saniyede bir işlem yapmak için alarm sinyali yakalayıcısı oluşturulur. */
    alarm(1);

    signal(SIGINT, cikis_sinyali); /* Kontrollü bir şekilde çıkış yapmak için SIGINT sinyali yakalanır. */

    srand((unsigned int) time(NULL));

    while (calis) {
        sleep(10); /* Alarm geldiği zaman uyku durumundan çıkılacağından değerin büyük olması önemli değildir. */

        gez = p + kyt_boyut * i; /* Gezici gösterici bir sonraki olay kaydına taşınır. */
        gez->sira = j; /* Her veride 1 artırılan sıra numarası */
        gez->veri = rand() % 100; /* 0 ile 99 aralığında rastgele bir değer veri olarak atanır. */

        i = i < 9 ? i + 1 : 0; /* Dairesel olarak gezmek için olan sayacın değeri 0 ile 9 aralığında tutulur. */
        j++;

        sem_post(sem); /* Veri yazıldıktan sonra okuyucu işlemi aktifleştirmek için semafor yükseltilir. */
        alarm(1);
    }
}

void cikis_sinyali(int s) {
    /* Paylaşılan bellek ile bağlantı kesilir. */
    shmdt(p);
    /* Paylaşılan bellek serbest bırakılır. */
    shmctl(shmid, IPC_RMID, 0);

    /* Semafor silinir. */
    sem_destroy(sem);

    exit(EXIT_SUCCESS);
}