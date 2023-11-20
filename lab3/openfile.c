#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "openfile.h"

#define dimr 40  //dimensione righe generica
#define dimc 30  //dimensione colonne generica

FILE *open_file(char nomefile[]) {

    FILE *file = fopen(nomefile, "r");
    if (file==NULL) { //controlliamo se il file esiste

        printf("Impossible to open file: wrong name or inesistent file.\n");
        return 1;
    }

    return file;

}
