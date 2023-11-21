#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stampa.h"

#define dimr 40  //dimensione righe generica
#define dimc 30  //dimensione colonne generica

int stampaArea(int area[][dimc]) {
    for (int i = 0; i < dimc; i++) { // cicli for per identificare bit per bit cosa fare
        for (int j = 0; j < dimr; j++) {
            if (area[j][i] == 1) {
                printf(".");  // Punto
            } else {
                printf(" ");  // Spazio vuoto
            }
        }
        printf("\n"); // andiamo a capo riga per riga
    }

    return 0;

}
