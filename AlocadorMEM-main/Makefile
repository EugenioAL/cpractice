CC = g++
CFLAGS = -Wall -g
 
all: bc
 
bc: bc.o aloca.o
	$(CC) -o bc bc.o aloca.o
 
bc.o: bc.cpp aloca.h
	$(CC) -o bc.o bc.cpp -c -W -Wall -ansi -pedantic
 
aloca.o: aloca.cpp aloca.h
	$(CC) -o aloca.o aloca.cpp -c -W -Wall -ansi -pedantic

run:
	./bc workloadmem0 > text.txt
 
clear:
	rm -rf *.o *~ bc