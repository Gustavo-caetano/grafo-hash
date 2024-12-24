#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hash.h"
/// variaveis globais
key obterChave = NULL;
int TAMANHO_MAX = -1;

bool ehPrimo(int numero)
{
    int maximoRepeticoes = sqrt(numero);
    for(int i = 2; i <= maximoRepeticoes; i++)
    {
        if(numero % i == 0) return false;
    }

    return true;
}

int encontrarPrimoProximo(int numero)
{
    int primoProximo = numero + 1;
    while(!ehPrimo(primoProximo)) primoProximo++;

    return primoProximo;
}

void **inicializarHash()
{
    void **hash;
    hash = (void**)malloc(TAMANHO_MAX * sizeof(void*));
    if(hash == NULL) 
        printf("array tabela hash nao inicializada\n");

    return hash;
}

TabelaHash *inicializarTabela(int tamanho)
{
    TabelaHash *tabelaaux;
    tabelaaux = (TabelaHash*)calloc(1, sizeof(TabelaHash));
    if(tabelaaux == NULL) 
        printf("tabela hash nao inicializada\n");

    tabelaaux->tamanho = tamanho;
    tabelaaux->tabela = inicializarHash();
    
    return tabelaaux;
} 

void limparTabela(TabelaHash **tabela)
{
    free((*tabela)->tabela);
    free(*tabela);
    *tabela = NULL;
}

int chaveHash(int chave)
{
    int chavehash = chave % TAMANHO_MAX;

    return chavehash;
}

bool inserirValor(TabelaHash **tabela, int chave, void *valor)
{
    if((*tabela) == NULL) 
    {
        printf("tabela não inicializada");
        return false;
    }
    if((*tabela)->tabela == NULL)
    {
        printf("array tabela não inicializada");
        return false;
    }
    
    int indiceInsercao = chaveHash(chave);

    while((*tabela)->tabela[indiceInsercao] != NULL) indiceInsercao++;

    (*tabela)->tabela[indiceInsercao] = valor;
    // printf("inserindo no indice %d valor %d\n", indiceInsercao, (obterChave)(tabela->tabela[indiceInsercao]));
    (*tabela)->tamanho++;
    if((*tabela)->tamanho > TAMANHO_MAX / 2)
    {
        // printf("tabela aumentou\n");
        expandirTabela(tabela);
    }

    return  true;
}

bool redistribuiValores(TabelaHash *tabelaAux, int chave, void *valor)
{
    int indiceInsercao = chaveHash(chave);

    while(tabelaAux->tabela[indiceInsercao] != NULL) indiceInsercao++;

    tabelaAux->tabela[indiceInsercao] = valor;

    return true;
}

bool expandirTabela(TabelaHash **tabela)
{
    int antigoTamanhoMaximo = TAMANHO_MAX;
    TAMANHO_MAX = encontrarPrimoProximo(2 * TAMANHO_MAX);

    TabelaHash *tabelaAux = inicializarTabela((*tabela)->tamanho);

    for(int i = 0; i < antigoTamanhoMaximo; i++)
    {
        if((*tabela)->tabela[i] != NULL)
        {   
            // printf("mudando o numero %d, novo hash %d \n", (obterChave)(tabela->tabela[i]),(obterChave)(tabela->tabela[i]));
            redistribuiValores(tabelaAux, (obterChave)((*tabela)->tabela[i]), (*tabela)->tabela[i]);
        }
    }
    limparTabela(tabela);

    *tabela = tabelaAux;
    return true;
}


bool removerValor(TabelaHash *tabela, int chave)
{
    int indiceHash = chaveHash(chave);
    
    while(tabela->tabela[indiceHash] != NULL &&  (obterChave)(tabela->tabela[indiceHash]) != chave)
        indiceHash++;

    if(tabela->tabela[indiceHash] == NULL) return false;

    tabela->tabela[indiceHash] = NULL;

    return true;
}

void* buscarValor(TabelaHash *tabelahash, int chave)
{
    if(tabelahash == NULL || tabelahash->tabela == NULL)
    {
        printf("tabela nao iniciada");
        return NULL;
    }
    if(obterChave == NULL)
    {
        printf("funcao nao iniciada");
        return NULL;
    }
    int indiceHash = chaveHash(chave);

    while(indiceHash < TAMANHO_MAX && tabelahash->tabela[indiceHash] != NULL  && chave != (obterChave)(tabelahash->tabela[indiceHash]))
    {
        indiceHash++;
    }
    
    if(indiceHash == TAMANHO_MAX) return NULL;
    
    return tabelahash->tabela[indiceHash];
}

void printarTabela(TabelaHash *tabela)
{
    for(int i = 0; i < TAMANHO_MAX; i++)
    {
        if(tabela->tabela[i] != NULL)
        {
            printf("indice %d valor %d\n", i, (obterChave)(tabela->tabela[i]));
        }
    }
}