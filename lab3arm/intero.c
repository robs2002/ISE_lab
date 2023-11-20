#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "intero.h"

#define dimr 40  //320
#define dimc 30  //240

int num_int(float t, int dim) {

    int s;
    float t_molt;

    t_molt= t*(dim-1);

    s=roundf(t_molt);

    return s;

}
