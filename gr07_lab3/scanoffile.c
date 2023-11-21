#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scanoffile.h"
#include "intero.h"
#include "algoritmo.h"

#define dimr 40  //dimensione righe generica
#define dimc 30  //dimensionme colonne generica

int scanfile(FILE *fp, int area[dimr][dimc]) {

    char comando;
    float x, y, x1, y1, x2, y2;
    int xx, yy, xx1, yy1, xx2, yy2;

    while (fscanf(fp, " %c ", &comando) == 1) { // leggiamo il comando

        if (comando=='P') { 

            fscanf(fp, " %f %f", &x, &y); // vediamo per quali coordinate dobbiamo eseguire il comando
            //printf("Comando: %c, x: %f, y: %f\n", comando, x, y);

            xx= num_int(x, dimr); // trasformo in interi normalizzati per 
            yy= num_int(y, dimc); // le dimensioni della matrice
 
            //printf(" xx: %d, yy: %d\n", xx, yy);

            area[xx][yy]=1; // portiamo a uno la coordinata selezionata

        } else if (comando=='L') {

            fscanf(fp, " %f %f %f %f", &x1, &y1, &x2, &y2); // vediamo per quali coordinate dobbiamo eseguire il comando
            //printf("Comando: %c, x1: %f, y1: %f, x2: %f, y2: %f \n", comando, x1, y1, x2, y2);

            xx1= num_int(x1, dimr);
            yy1= num_int(y1, dimc); // trasformo in interi normalizzati per 
            xx2= num_int(x2, dimr); // le dimensioni della matrice
            yy2= num_int(y2, dimc);

            algoritmo_di_linea(xx1, yy1, xx2, yy2, area); // unisco le due coordinate

            //printf(" xx1: %d, yy1: %d, xx2: %d, yy2: %d \n", xx1, yy1, xx2, yy2);

        } else {

            printf("Comando: %c sbagliato.\n", comando); // nel caso ci siano comandi non usuali

        }

        //printf("Comando: %c, x: %f, y: %f\n", comando, x, y);
    }
    return 0;
}
