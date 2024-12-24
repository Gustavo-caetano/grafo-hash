#ifndef HASH_H_
#define HASH_H_

#include <stdbool.h>

typedef struct TabelaHashStruct
{
    void **tabela;
    int tamanho;
} TabelaHash;

typedef int (*key)(void* valor);

extern int TAMANHO_MAX;

//funcao pra obter chave
extern key obterChave;


//funcoes matematicas
int encontrarPrimoProximo(int numero);
bool ehPrimo(int numero);


//funcoes para tabela
void **inicializarHash();
TabelaHash *inicializarTabela(int tamanho);
int chaveHash(int chave);
bool expandirTabela(TabelaHash **tabela);

//crud
bool inserirValor(TabelaHash **tabela, int chave, void *valor);
bool removerValor(TabelaHash *tabela, int chave);
void* buscarValor(TabelaHash *tabela, int chave);
// bool atualizarValor(int chave, void* valor);

void printarTabela(TabelaHash *tabela);

#endif /* !HASH_H_ */