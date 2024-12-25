#ifndef PILHA_H_
#define PILHA_H_

#include <stdbool.h>

typedef struct ElementoPilha {
    void *valor;
    struct ElementoPilha *proximo;
    struct ElementoPilha *anterior;
} ElementoPilha;

typedef struct {
    ElementoPilha *topo;
    ElementoPilha *base;
    int quantidade;
} Pilha;

typedef bool (*PonteiroFuncao)(void *valorA, void *valorB);
typedef void (*Impressao)(void *valor);

extern PonteiroFuncao comparador;
extern Impressao funcaoImpressao;

//funcao basicas
ElementoPilha *inicializaElemento(void *valor);
Pilha *inicializaPilha();

//crud
bool push(Pilha *pilha, void *valor);
void *pop(Pilha *pilha);

void imprimirPilha(Pilha *pilha);
void limparPilha(Pilha *pilha);

#endif