#include <stdio.h>
#include <stdlib.h>
#include "grafo/grafo.h"

int main()
{
    iniciarGrafo();
    
    for(int i = 1; i < 20; i++)
    {   
        adicionaVertice(i);
        if(i > 1)
        {
            adicionaAresta(i, i - 1);
        }
    }

    imprimirGrafo();

    // ehEuleriano();
    // caminhoHamiltoniano();
    return 0;
}