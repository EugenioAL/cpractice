CXX = g++
CFLAGS = -c -W -Wall -ansi -pedantic

all: main

main: main.o grafo.o misc.o
	$(CXX) -o main main.o grafo.o misc.o

main.o: main.cpp grafo.hpp
	$(CXX) -o main.o main.cpp $(CFLAGS)

grafo.o: grafo.cpp grafo.hpp
	$(CXX) -o grafo.o grafo.cpp $(CFLAGS)

misc.o: misc.cpp grafo.hpp
	$(CXX) -o misc.o misc.cpp $(CFLAGS)

run:
	./main

clean:
	rm -rf *.o *~ main