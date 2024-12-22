#ifndef HASH_H_
#define HASH_H_

#include <stdbool.h>

typedef struct
{
    void **tabela;
    int tamanho;
} TabelaHash;

typedef int (*key)(void* valor);

static int TAMANHO_MAX = 7;
extern TabelaHash *tabelahash;

//funcao pra obter chave
extern key obterChave;

extern key comparaValor;

//funcoes matematicas
int encontrarPrimoProximo(int numero);
bool ehPrimo(int numero);


//funcoes para tabela
void **inicializarHash();
TabelaHash *inicializarTabela(int tamanho);
int chaveHash(int chave);
bool expandirTabela();

//crud
bool inserirValor(int chave, void *valor);
bool removerValor(void *valor);
void* buscarValor(int chave);
// bool atualizarValor(int chave, void* valor);

void printarTabela();

#endif /* !HASH_H_ */