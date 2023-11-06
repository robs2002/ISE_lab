#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//int riga_corretta(char*);

int main(){
    // Chiedo file all'utente e provo ad aprirlo
    char file[100] = "prova.txt";
    /*
    printf("Inserisci il nome del file: ");
    scanf("%s", file);
    */
    
    FILE *fp = fopen(file, "r");
    if (fp == NULL){    // file non esiste e quindi termino il programma
        printf("File '%s' non esistente", file);
        return 0;
    }
    
    // Leggo file
    //char riga[100];
    
    //fgets(riga, sizeof(riga), fp);  // prima riga del file
    //int n = riga_corretta(riga);
       

    /*
    while( fgets(riga, sizeof(riga), fp) != NULL){
        printf("%s", riga);
    }
*/

    char comando;
    float x;
    float y;
    
        fscanf(fp, "%c %f %f", comando, x, y);
        printf("comando: %c, x: %f, y: %f\n", comando, x, y);
    

    // chiudo file
    fclose(fp);
    return 0;
}

/*
int riga_corretta(char* row){
    char sub1[10];
    char sub2[10];
    
    if ( (row[0] != 'P') & (row[0] != 'L') ){   // primo carattere diverso da P e L
        printf("Primo carattere diverso da P o L");
        return 1;
    }

    if ( row[1] != ' ' ){
        printf("Secondo carattere diverso da uno spazio");  // secondo carattere diverso da spazio
        return 1;
    }

    if ( (row[2] != '0') & (row[2] != '1') ){
        printf("Terzo carattere diverso da 0 e 1");  
        return 1;
    }

    if ( row[3] != '.' ) {
        printf("Quarto carattere diverso da punto"); 
        return 1;
    }

    int indice = 4;
    
    while ( isdigit(row[indice]) ){
        indice++;
    }
    
    strncpy(sub1, row+2, indice-2);
    //printf("\n%s\n", sub1);
    float x = atof(sub1);
    printf("%f\n", x);


    if ( row[indice] != ' ' ){
        printf("Secondo carattere diverso da uno spazio");  // secondo carattere diverso da spazio
        return 1;
    }
    indice++;
    int indice_inizio = indice;

    while ( isdigit(row[indice]) ){
        indice++;
    }

    strncpy(sub2, row+2, indice-indice_inizio);
    //printf("\n%s\n", sub2);
    float y = atof(sub2);
    printf("%f\n", y);


    return 1;
}
*/