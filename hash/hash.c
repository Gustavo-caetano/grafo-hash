#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hash.h"
/// variaveis globais
key obterChave = NULL;
key comparaValor = NULL;
TabelaHash *tabelahash = NULL;

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
    TabelaHash *tabelahashaux;
    tabelahashaux = (TabelaHash*)malloc(sizeof(TabelaHash));
    if(tabelahashaux == NULL) 
        printf("tabela hash nao inicializada\n");

    tabelahashaux->tamanho = tamanho;
    tabelahashaux->tabela = inicializarHash();

    for(int i = 0; i < TAMANHO_MAX; i++)
    {
        tabelahashaux->tabela[i] = NULL;
    }
    
    return tabelahashaux;
} 

void limparTabela()
{
    free(tabelahash->tabela);
    free(tabelahash);
}

int chaveHash(int chave)
{
    int chavehash = chave % TAMANHO_MAX;

    return chavehash;
}

bool inserirValor(int chave, void *valor)
{
    if(tabelahash == NULL) 
    {
        printf("tabela não inicializada");
        return false;
    }
    if(tabelahash->tabela == NULL)
    {
        printf("array tabela não inicializada");
        return false;
    }

    int indiceInsercao = chaveHash(chave);

    while(tabelahash->tabela[indiceInsercao] != NULL) indiceInsercao++;

    tabelahash->tabela[indiceInsercao] = valor;
    // printf("inserindo no indice %d valor %d\n", indiceInsercao, (obterChave)(tabelahash->tabela[indiceInsercao]));
    tabelahash->tamanho++;

    if(tabelahash->tamanho > TAMANHO_MAX / 2)
    {
        // printf("tabela aumentou\n");
        expandirTabela();
    }

    return  true;
}

bool inserirValorAux(TabelaHash *tabelahashAux, int chave, void *valor)
{
    int indiceInsercao = chaveHash(chave);

    while(tabelahashAux->tabela[indiceInsercao] != NULL) indiceInsercao++;

    tabelahashAux->tabela[indiceInsercao] = valor;
    tabelahashAux->tamanho++;

    return true;
}

bool expandirTabela()
{
    int antigoTamanhoMaximo = TAMANHO_MAX;
    TAMANHO_MAX = encontrarPrimoProximo(2 * TAMANHO_MAX);

    TabelaHash *tabelaAux = inicializarTabela(tabelahash->tamanho);

    for(int i = 0; i < antigoTamanhoMaximo; i++)
    {
        if(tabelahash->tabela[i] != NULL)
        {   
            // printf("mudando o numero %d, novo hash %d \n", (obterChave)(tabelahash->tabela[i]),(obterChave)(tabelahash->tabela[i]));
            inserirValorAux(tabelaAux, (obterChave)(tabelahash->tabela[i]), tabelahash->tabela[i]);
        }
    }

    limparTabela();

    tabelahash = tabelaAux;

    return true;
}


bool removerValor(void *valor)
{
    int indiceHash = chaveHash((obterChave)(valor));
    
    while(tabelahash->tabela[indiceHash] != NULL &&  !(comparaValor)(tabelahash->tabela[indiceHash]))
        indiceHash++;

    if(tabelahash->tabela[indiceHash] == NULL) return false;

    tabelahash->tabela[indiceHash] = NULL;

    return true;
}

void* buscarValor(int chave)
{
    int indiceHash = chaveHash(chave);

    while(tabelahash->tabela[indiceHash] != NULL && chave != (obterChave)(tabelahash->tabela[indiceHash]))
        indiceHash++;
    
    return tabelahash->tabela[indiceHash];
}

void printarTabela()
{
    for(int i = 0; i < TAMANHO_MAX; i++)
    {
        if(tabelahash->tabela[i] != NULL)
        {
            printf("indice %d valor %d\n", i, (obterChave)(tabelahash->tabela[i]));
        }
    }
}