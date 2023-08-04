#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_ALFABETO 26
typedef enum { false, true } bool;
typedef bool TIPO_DE_RETORNO;

// Os dados armazenados vão aqui:
typedef struct no {
    struct no *filhos[N_ALFABETO];
    TIPO_DE_RETORNO fim;
} NO;

typedef NO *PONT;
PONT criaNO();
PONT inicializa();
int mapearIndice(char c);
void insere(PONT raiz, char *chave);
bool busca(PONT raiz, char *chave);