convertitore: main.o converter.o test.o
	g++ -std=c++11 -Wall -o convertitore main.o converter.o test.o

main.o: main.cpp test.h
	g++ -std=c++11 -Wall -c main.cpp

converter.o: converter.cpp converter.h
	g++ -std=c++11 -Wall -c converter.cpp

test.o: test.cpp test.h converter.h
	g++ -std=c++11 -Wall -c test.cpp
	
