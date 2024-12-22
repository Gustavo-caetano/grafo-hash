#include <stdlib.h>
#include <stdio.h>
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

No *inicializarNo(int vertice)
{
    No *noAux = (No *)malloc(sizeof(No));
    if (noAux == NULL)
        printf("No nao inicializado\n");

    noAux->vertice = vertice;
    noAux->qtdArestas = 0;
    noAux->arestas = NULL;

    return noAux;
}

void iniciarGrafo()
{
    iniciandoFuncoes();
    tabelahash = inicializarTabela(0);
}

bool adicionaVertice(int vertice)
{
    if (buscarValor(vertice) != NULL)
        return false;

    No *novoVertice = inicializarNo(vertice);

    inserirValor(vertice, novoVertice);

    return true;
}

bool buscarAresta(No *vertice, int aresta)
{
    for (int i = 0; i < vertice->qtdArestas; i++)
    {
        if (aresta == vertice->arestas[i])
            return true;
    }

    return false;
}

bool adicionaAresta(int verticeA, int verticeB)
{
    No *noVerticeA = buscarValor(verticeA);
    No *noVerticeB = buscarValor(verticeB);

    if (noVerticeA == NULL || noVerticeB == NULL)
    {
        printf("vertice inexistente\n");
        return false;
    }

    if (buscarAresta(noVerticeA, verticeB))
    {
        printf("ja existe aresta\n");
        return false;
    }

    bool insercao = adicionaArestaNoVertice(noVerticeA, verticeB) && adicionaArestaNoVertice(noVerticeB, verticeA);

    return insercao;
}

bool adicionaArestaNoVertice(No *vertice, int aresta)
{

    if (vertice->arestas == NULL)
    {
        vertice->arestas = (int *)malloc(5 * sizeof(int));
    }
    else if (vertice->qtdArestas != 0 && vertice->qtdArestas % 5 == 0)
    {
        int quantidade = (vertice->qtdArestas / 5 + 1) * 5;
        vertice->arestas = (int *)realloc(vertice->arestas, quantidade * sizeof(int));
    }

    if (vertice->arestas == NULL)
        return false;

    vertice->arestas[vertice->qtdArestas] = aresta;
    vertice->qtdArestas++;
    return true;
}

void ehEuleriano()
{
    bool eheuleriano = true;

    for (int i = 0; i < TAMANHO_MAX; i++)
    {
        if (tabelahash->tabela[i] != NULL)
        {
            No *vertice = (No *)tabelahash->tabela[i];
            if (vertice->qtdArestas % 2 != 0)
            {
                eheuleriano = false;
                break;
            }
        }
    }

    if (eheuleriano)
    {
        printf("o grafo eh euleriano\n");
    }
    else
    {
        printf("o grafo nao eh euleriano\n");
    }
}

void caminhoHamiltoniano()
{
    bool ehhamiltoniano = true;

    if (tabelahash->tamanho < 3)
    {
        ehhamiltoniano = false;
    }
    else
    {
        int corte = tabelahash->tamanho / 2;
        for (int i = 0; i < TAMANHO_MAX; i++)
        {
            if (tabelahash->tabela[i] != NULL)
            {
                No *vertice = (No *)tabelahash->tabela[i];
                if (vertice->qtdArestas < corte)
                {
                    ehhamiltoniano = false;
                    break;
                }
            }
        }
    }

    if (ehhamiltoniano)
    {
        printf("o grafo eh hamiltoniano\n");
    }
    else
    {
        printf("o grafo nao eh hamiltonianoS\n");
    }
}

void imprimirVertice(No *vertice)
{
    printf("%d -> ", vertice->vertice);

    for (int i = 0; i < vertice->qtdArestas; i++)
    {
        printf("%d ", vertice->arestas[i]);
    }

    printf("\n");
}
void imprimirGrafo()
{
    for (int i = 0; i < TAMANHO_MAX; i++)
    {
        if (tabelahash->tabela[i] != NULL)
        {
            imprimirVertice((No *)tabelahash->tabela[i]);
        }
    }
}