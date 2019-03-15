#include <stdio.h>
#include "Random.h"

int main() {
    Random random = random_olustur();

    printf("%d\n", rastgele_sayi(random));
    printf("%d\n", rastgele_sayi(random));
    printf("%d\n", rastgele_sayi(random));
    printf("%d\n", rastgele_sayi(random));
    printf("%d\n", rastgele_sayi(random));

    random->yok_et();

    return 0;
}