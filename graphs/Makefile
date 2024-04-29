CC = gcc
CP = g++
CFLAGS =-Wall -c

all: main

main: grafo.o misc.o main.o
    $(CP) grafo.o misc.o main.o -o main

grafo.o: grafo.cpp 
   $(CP) $(CFLAGS) grafo.cpp

misc.o: misc.cpp
    $(CP) $(CFLAGS) misc.cpp

main.o: main.c
    $(CP) $(CFLAGS) main.cpp

clean:
    rm *.o main