#include <stdio.h>
#include <stdlib.h>
#include "grafo/grafo.h"


int main()
{
    iniciarGrafo();

    int max = 6;
    for(int i = 0; i < max; i++)
    {   
        adicionaVertice(i);
    }

    adicionaAresta(0, 1);
    adicionaAresta(0, 3);

    adicionaAresta(1, 2);
    adicionaAresta(1, 4);
    adicionaAresta(1, 5);

    adicionaAresta(2, 4);
    adicionaAresta(2, 3);
    adicionaAresta(2, 5);

    imprimirGrafo();
    // ehEuleriano();
    // caminhoHamiltoniano();
    hierholzer();
    return 0;
}