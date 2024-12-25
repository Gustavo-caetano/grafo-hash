#ifndef GRAFO_H_
#define GRAFO_H_

#include <stdbool.h>
#include "../hash/hash.h"

typedef struct {
    int verticeAresta;
    bool marcado;
} Aresta;

typedef struct NoStruct
{
    int vertice;
    Aresta* arestas;
    int qtdArestas;
} No;

extern TabelaHash *grafo;
extern int TAMANHO_MAX;

void iniciandoFuncoes();
No* inicializarNo(int vertice);
void iniciarGrafo();

//crud
bool adicionaVertice(int vertice);
bool removeVertice(int vertice);
bool adicionaAresta(int verticeA, int verticeB);
bool removeAresta(int verticeA, int verticeB);
bool adicionaArestaNoVertice(No *vertice, int aresta);
bool removerArestaNoVertice(No* vertice, int aresta);
No* buscaVertice(int vertice);

//impressao
void imprimirVertice(No* vertice);
void imprimirGrafo();

//informacoes do grafo
bool ehEuleriano();
void caminhoHamiltoniano();
void hierholzer();


#endif /* !GRAFO_H_ */