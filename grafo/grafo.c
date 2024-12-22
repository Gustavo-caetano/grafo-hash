#include "grafo.h"

int obterChaveGrafo(void *valor)
{
    No *noAux = (No *)valor;

    return noAux->vertice;
}

void iniciandoFuncoes()
{
    obterChave = obterChaveGrafo;
}