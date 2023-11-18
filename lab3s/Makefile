linea: main.o stampa.o algoritmo.o scanoffile.o intero.o openfile.o
	gcc -static -o linea main.o stampa.o algoritmo.o scanoffile.o intero.o openfile.o -lm

main.o: main.c stampa.h algoritmo.h scanoffile.o intero.h openfile.h 
	gcc -static -c main.c

stampa.o: stampa.c stampa.h
	gcc -static -c stampa.c

algoritmo.o: algoritmo.c algoritmo.h
	gcc -static -c algoritmo.c

scanoffile.o: scanoffile.c scanoffile.h algoritmo.h intero.h
	gcc -static -c scanoffile.c

intero.o: intero.c intero.h
	gcc -static -c intero.c  

openfile.o: openfile.c openfile.h
	gcc -static -c openfile.c

	
