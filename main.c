#include <stdio.h>
#include <stdlib.h>
#include "grafo/grafo.h"

int main()
{
    iniciarGrafo();
    
    for(int i = 1; i < 10; i++)
    {   
        adicionaVertice(i);
    }
    adicionaAresta(1, 2);
    adicionaAresta(1, 3);

    adicionaAresta(2, 3);

    adicionaAresta(4, 5);

    adicionaAresta(5, 6);

    adicionaAresta(6, 4);

    imprimirGrafo();

    ehEuleriano();
    caminhoHamiltoniano();
    return 0;
}