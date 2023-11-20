#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stampa.h"

#define dimr 40  //320
#define dimc 30  //240

int stampaArea(int area[][dimc]) {
    for (int i = 0; i < dimc; i++) {
        for (int j = 0; j < dimr; j++) {
            if (area[j][i] == 1) {
                printf(".");  // Punto
            } else {
                printf(" ");  // Spazio vuoto
            }
        }
        printf("\n");
    }

    return 0;

}
