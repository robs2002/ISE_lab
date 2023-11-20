#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "algoritmo.h"

#define dimr 40  //dimensione righe generica
#define dimc 30  //dimensione colonne generica

int algoritmo_di_linea(int x1, int y1, int x2, int y2, int area[][dimc]){

    // Assegna le coordinate iniziali
    int DX = x2 - x1;
    int DY = y2 - y1;

    // Verifica se è necessario scambiare DX e DY se DY>DX
    int swap = 0;
    if (abs(DX) < abs(DY)) {
        swap = 1;
        int temp = DX;
        DX = DY;
        DY = temp;
    }

    int a = abs(DY);
    int b = -abs(DX);

    int x = x1;
    int y = y1;

    int d = 2 * a + b;

    int q = 1;
    int s = 1;
    if (x1 > x2) //se x1>x2 metto q=-1
        q = -1;
    if (y1 > y2)
        s = -1;
    area[x][y]=1;   //assegnazione punto iniziale
    area[x2][y2]=1; //assegnazione punto finale

    for (int k = 0; k < -b; k += 1) {

        if (d > 0) {
            x = x + q;
            y = y + s;
            d = d + 2 * (a + b);
        } else {
            x = x + q;
            if (swap == 1) {
                y = y + s;
                x = x - q;
            }
            d = d + 2 * a;
        }
        //printf("x: %d, y: %d, k: %d\n", x, y, k);
        area[x][y]=1;
    }

    return 0;
}
