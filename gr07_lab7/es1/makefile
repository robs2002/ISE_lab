convertitore: main.o converter.o 
	g++ -std=c++11 -Wall -o convertitore main.o converter.o 

main.o: main.cpp converter.h
	g++ -std=c++11 -Wall -c main.cpp

converter.o: converter.cpp converter.h
	g++ -std=c++11 -Wall -c converter.cpp
