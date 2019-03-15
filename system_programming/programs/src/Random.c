#include <time.h>
#include "Random.h"

Random random_olustur() {
    Random this;

    unsigned int *seed_alloc = malloc(0);

    this = (Random) malloc(sizeof(struct RANDOM));
    this->besleme = *seed_alloc;
    this->yok_et = &random_yok_et;

    free(seed_alloc);

    return this;
}

void random_yok_et(Random random) {
    if (random == NULL) return;

    free(random);
}

unsigned int rastgele_sayi(Random random) {
    time_t tamzaman;
    struct tm *zamanbilgisi;

    time(&tamzaman);
    zamanbilgisi = localtime(&tamzaman);

    unsigned int lfsr = random->besleme * zamanbilgisi->tm_sec;

    unsigned int bit = (((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1);
    return (random->besleme = (lfsr >> 1) | (bit << 15));
}