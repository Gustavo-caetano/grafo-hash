all: main

main: main.o grafo.o hash.o
	gcc -o main main.o grafo.o hash.o -lm

main.o: main.c
	gcc -o main.o main.c -c -W -Wall -pedantic -Wno-unused-variable

grafo.o: grafo/grafo.c grafo/grafo.h
	gcc -o grafo.o grafo/grafo.c -c -W -Wall -pedantic -Wno-unused-variable

hash.o: hash/hash.c hash/hash.h
	gcc -o hash.o hash/hash.c -c -W -Wall -pedantic -Wno-unused-variable

clean:
	rm -rf *.o main 