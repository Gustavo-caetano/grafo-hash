all: main

main: main.o grafo.o hash.o pilha.o
	gcc -o main main.o grafo.o hash.o pilha.o -lm -g

main.o: main.c
	gcc -o main.o main.c -c -W -Wall -pedantic -Wno-unused-variable -g

grafo.o: grafo/grafo.c grafo/grafo.h
	gcc -o grafo.o grafo/grafo.c -c -W -Wall -pedantic -Wno-unused-variable -g

hash.o: hash/hash.c hash/hash.h
	gcc -o hash.o hash/hash.c -c -W -Wall -pedantic -Wno-unused-variable -g

pilha.o: pilha/pilha.c pilha/pilha.h 
	gcc -o pilha.o pilha/pilha.c -c -W -Wall -pedantic -Wno-unused-variable -g

clean:
	rm -rf *.o main 