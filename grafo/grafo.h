#ifndef GRAFO_H_
#define GRAFO_H_

#include <stdbool.h>
#include "../hash/hash.h"

typedef struct NoStruct
{
    int vertice;
    int* arestas;
    int qtdArestas;
} No;

void iniciandoFuncoes();
No* inicializarNo(int vertice);
void iniciarGrafo();

//crud
bool adicionaVertice(int vertice);
bool adicionaAresta(int verticeA, int verticeB);
bool adicionaArestaNoVertice(No *vertice, int aresta);

//impressao
void imprimirVertice(No* vertice);
void imprimirGrafo();

//informacoes do grafo
void ehEuleriano();
void caminhoHamiltoniano();



#endif /* !GRAFO_H_ */