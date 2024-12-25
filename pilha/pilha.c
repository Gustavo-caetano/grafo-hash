#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

PonteiroFuncao comparador = NULL;
Impressao funcaoImpressao = NULL;

bool pilhaNaoInicializada(Pilha *pilha)
{
    if(pilha == NULL)
    {
        printf("pilha nao iniciada\n");
        return true;
    }
    return false;
}

ElementoPilha *inicializaElemento(void *valor)
{
    ElementoPilha *novoElemento;
    novoElemento = (ElementoPilha *)malloc(sizeof(ElementoPilha));
    if(!novoElemento)
        return NULL;
    novoElemento->proximo = NULL;
    novoElemento->anterior = NULL;

    novoElemento->valor = valor;

    return novoElemento;
}

Pilha *inicializaPilha()
{
    Pilha *pilhaAux;
    pilhaAux = (Pilha *)malloc(sizeof(Pilha));
    if(!pilhaAux)
        return NULL;

    pilhaAux->base = NULL;
    pilhaAux->topo = NULL;
    pilhaAux->quantidade = 0;
    return pilhaAux;
}

bool push(Pilha *pilha, void *valor)
{
    ElementoPilha *novoElemento = inicializaElemento(valor);
    if(pilhaNaoInicializada(pilha))
    {
        return false;
    }

    if (!pilha->base)
    {
        pilha->base = novoElemento;
        pilha->topo = pilha->base;
        pilha->quantidade++;
        return true;
    }

    novoElemento->anterior = pilha->topo;

    pilha->topo->proximo = novoElemento;
    pilha->topo = novoElemento;

    pilha->quantidade++;

    return true;
}

void *pop(Pilha *pilha)
{
    if(pilhaNaoInicializada(pilha))
    {
        return NULL;
    }
    
    if(pilha->quantidade == 0)
    {
        printf("pilha vazia pra remover\n");
        return NULL;
    }
    ElementoPilha *elementoAux = pilha->topo;

    if(pilha->quantidade == 1)
    {
        pilha->base = NULL;
        pilha->topo = NULL;
        pilha->quantidade--;
        return elementoAux->valor;
    }

    pilha->topo = pilha->topo->anterior;
    pilha->topo->proximo = NULL;

    pilha->quantidade--;

    return elementoAux->valor;

}

void imprimirPilha(Pilha *pilha)
{
    if(pilhaNaoInicializada(pilha) || pilha->quantidade == 0)
    {
        printf("pilha vazia para imprimir");
        return;
    }
    
    ElementoPilha *elementoAux = pilha->base;
    while (elementoAux)
    {
        (funcaoImpressao)(elementoAux->valor);
        elementoAux = elementoAux->proximo;
    }
    printf("\n");
}

void limparPilha(Pilha *pilha)
{
    ElementoPilha *elementoAux, *elementoRemovido;
    elementoAux = pilha->base;
    elementoRemovido = NULL;

    while (elementoAux)
    {
        elementoRemovido = elementoAux;
        elementoAux = elementoAux->proximo;
        free(elementoRemovido);
    }
    
    free(pilha);
}