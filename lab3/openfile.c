#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "openfile.h"

#define dimr 40  //320
#define dimc 30  //240

FILE *open_file(char nomefile[]) {

    FILE *file = fopen(nomefile, "r");
    if (file==NULL) { //controlliamo se il file c'è

        perror("Impossible to open file: wrong name or inesistent file.\n");
        exit(1);
    }

    return file;

}
