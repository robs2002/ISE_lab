#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define dimr 40  //320
#define dimc 30  //240

int scanfile(FILE *fp, int area[][dimc]);

int algoritmo_di_linea(int x1, int y1, int x2, int y2, int area[][dimc]);

FILE *open_file(char nomefile[]);

int num_int(float t, int dim);

int stampaArea(int area[][dimc]);

int main() {

    char nomefile[100];

    //chiedere il nome del file da analizzare
    printf("Hello, write here the name of the file you want to work with:\n");
    scanf("%s", nomefile);

    printf("You inserted the file %s \n", nomefile);

    FILE *fp = open_file(nomefile);

    int area[dimr][dimc]={{0}}; //definire matrice tutta a 0

    scanfile(fp, area);

    stampaArea(area);

    fclose(fp); //chiudere file

    return 0;

}

//Funzione per aprire il file e controllare se esiste ed è valido
FILE *open_file(char nomefile[]) {

    FILE *file = fopen(nomefile, "r");
    if (file==NULL) { //controlliamo se il file c'è

        printf("Impossible to open file: wrong name or inesistent file.\n");
        return 1;
    }

    return file;

}

//Funzione per prendere i comandi dal file e salvare le coordinate in cui scrivere in una matrice
int scanfile(FILE *fp, int area[dimr][dimc]) {

    char comando;
    float x, y, x1, y1, x2, y2;
    int xx, yy, xx1, yy1, xx2, yy2;

    while (fscanf(fp, " %c ", &comando) == 1) {

        if (comando=='P') { //se il comando è P allora la matrice di quella riga e quella colonna è 1

            fscanf(fp, " %f %f", &x, &y);
            //printf("Comando: %c, x: %f, y: %f\n", comando, x, y);

            xx= num_int(x, dimr);
            yy= num_int(y, dimc);

            //printf(" xx: %d, yy: %d\n", xx, yy);

            area[xx][yy]=1;

        } else if (comando=='L') {

            fscanf(fp, " %f %f %f %f", &x1, &y1, &x2, &y2);
            //printf("Comando: %c, x1: %f, y1: %f, x2: %f, y2: %f \n", comando, x1, y1, x2, y2);

            xx1= num_int(x1, dimr);
            yy1= num_int(y1, dimc);
            xx2= num_int(x2, dimr);
            yy2= num_int(y2, dimc);

            algoritmo_di_linea(xx1, yy1, xx2, yy2, area);
            //bresenham_line(xx1, yy1, xx2, yy2, area);

            //printf(" xx1: %d, yy1: %d, xx2: %d, yy2: %d \n", xx1, yy1, xx2, yy2);

        } else {

            printf("Comando: %c sbagliato.\n", comando);

        }

        //printf("Comando: %c, x: %f, y: %f\n", comando, x, y);
    }
    return 0;
}

//Funzione che descrive l'algoritmo di linea per il comando L
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

    for (int k = 1; k < -b; k += 1) {

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

// Funzione per trasformare i numeri in interi
int num_int(float t, int dim) {

    int s;
    float t_molt;

    t_molt= t*(dim-1);

    s=roundf(t_molt);

    return s;

}

// Funzione per stampare l'area con i punti disegnati
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
