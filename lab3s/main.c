#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scanoffile.h"
#include "algoritmo.h"
#include "intero.h"
#include "openfile.h"
#include "stampa.h"


#define dimr 40  //320
#define dimc 30  //240

int main() {

    char nomefile[100];

    //chiedere il nome del file da analizzare
    printf("Hello, write here the name of the file you want to work with:\n");
    scanf("%s", nomefile);

    printf("You inserted the file %s \n", nomefile);

    FILE *fp = open_file(nomefile);

    //link file da aprire
    //C:\Users\rober\CLionProjects\es1\grup.txt

    int area[dimr][dimc]={{0}}; //definire matrice tutta a 0

    scanfile(fp, area);

    stampaArea(area);

    fclose(fp); //chiudere file

    return 0;

}
