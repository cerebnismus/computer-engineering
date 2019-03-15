#ifndef RANDOM_H
#define RANDOM_H

#include "stdlib.h"

struct RANDOM {
    unsigned int besleme;

    void (*yok_et)();
};

typedef struct RANDOM *Random;

Random random_olustur();

void random_yok_et(Random);

unsigned int rastgele_sayi(Random rand);

#endif //RANDOM_H
