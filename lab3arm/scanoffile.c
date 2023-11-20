#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scanoffile.h"
#include "intero.h"
#include "algoritmo.h"

#define dimr 40  //320
#define dimc 30  //240

int scanfile(FILE *fp, int area[dimr][dimc]) {

    char comando;
    float x, y, x1, y1, x2, y2;
    int xx, yy, xx1, yy1, xx2, yy2;

    while (fscanf(fp, " %c ", &comando) == 1) {

        if (comando=='P') { //se il comando è P allora la matrice di quella riga e quella colonna è 1

            fscanf(fp, " %f %f", &x, &y);
            printf("Comando: %c, x: %f, y: %f\n", comando, x, y);

            xx= num_int(x, dimr);
            yy= num_int(y, dimc);

            printf(" xx: %d, yy: %d\n", xx, yy);

            area[xx][yy]=1;

        } else if (comando=='L') {

            fscanf(fp, " %f %f %f %f", &x1, &y1, &x2, &y2);
            printf("Comando: %c, x1: %f, y1: %f, x2: %f, y2: %f \n", comando, x1, y1, x2, y2);

            xx1= num_int(x1, dimr);
            yy1= num_int(y1, dimc);
            xx2= num_int(x2, dimr);
            yy2= num_int(y2, dimc);

            algoritmo_di_linea(xx1, yy1, xx2, yy2, area);

            printf(" xx1: %d, yy1: %d, xx2: %d, yy2: %d \n", xx1, yy1, xx2, yy2);

        } else {

            printf("Comando: %c sbagliato.\n", comando);

        }

        //printf("Comando: %c, x: %f, y: %f\n", comando, x, y);
    }
    return 0;
}
