#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
typedef int TIPOCHAVE;

// Os dados armazenados vão aqui:
typedef struct aux {
    TIPOCHAVE chave;
    struct aux *esq;
    struct aux *dir;
    int altura_do_NO;
} NO, *PONT;

PONT CriaNO(TIPOCHAVE ch);
PONT inicializa();
PONT direita(PONT r);
PONT esquerda(PONT r);
PONT esquerdadireita(PONT r);
PONT direitaesquerda(PONT r);
int max(int a, int b);
int altura(PONT raiz);
PONT insere(PONT raiz, TIPOCHAVE ch);