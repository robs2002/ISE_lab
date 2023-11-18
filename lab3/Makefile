linea: main.o stampa.o algoritmo.o scanoffile.o intero.o openfile.o
	gcc -o linea main.o stampa.o algoritmo.o scanoffile.o intero.o openfile.o -lm

main.o: main.c stampa.h algoritmo.h scanoffile.o intero.h openfile.h 
	gcc -c main.c

stampa.o: stampa.c stampa.h
	gcc -c stampa.c

algoritmo.o: algoritmo.c algoritmo.h
	gcc -c algoritmo.c

scanoffile.o: scanoffile.c scanoffile.h algoritmo.h intero.h
	gcc -c scanoffile.c

intero.o: intero.c intero.h
	gcc -c intero.c  

openfile.o: openfile.c openfile.h
	gcc -c openfile.c

	
