#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scanoffile.h"
#include "algoritmo.h"
#include "intero.h"
#include "stampa.h"


#define dimr 40  //dimensione righe generica
#define dimc 30  //dimensione colonne generica

int main() {

    char nomefile[100]; // nome del file dal quale voglio leggere le operazioni

    //chiedere il nome del file da analizzare
    printf("Hello, write here the name of the file you want to work with:\n");
    scanf("%s", nomefile); 
    // salvo il nome del file e lo stampo per controllo
    printf("You inserted the file %s \n", nomefile); 

    FILE *fp = fopen(nomefile, "r");
    
    if (fp == NULL) {
        printf("Error opening the file: file not exists or wrong name");
        return 1;  // Esce dal programma con un codice di errore
    }

    int area[dimr][dimc]={{0}}; //definire matrice tutta a 0

    scanfile(fp, area); // scansione del file

    stampaArea(area); // stampare area creata

    // Forza la chiusura del file
    if (fclose(fp) != 0) {
        printf("Error closing the file: impossible to close it");
        return 1;  // Esce dal programma con un codice di errore
    }

    return 0;

}
