#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "intero.h"

#define dimr 40  //dimensione righe generica
#define dimc 30  //dimensione colonne generica

int num_int(float t, int dim) {

    int s;
    float t_molt;

    t_molt= t*(dim-1); // moltiplichiamo per la massima dimensione 

    s=roundf(t_molt); // arrotondiamo ad intero

    return s;

}
