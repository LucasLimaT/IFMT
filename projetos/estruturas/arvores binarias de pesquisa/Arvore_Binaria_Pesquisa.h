#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
typedef int TIPOCHAVE;

// Os dados armazenados vão aqui:
typedef struct aux {
    TIPOCHAVE chave;
    struct aux *esq, *dir;
} NO;

typedef NO *PONT;
PONT inicializa();
PONT CriaNovoNo(TIPOCHAVE ch);
PONT adiciona(PONT raiz, PONT no);
PONT contem(TIPOCHAVE ch, PONT raiz);
int numeroNos(PONT raiz);
void ExibirArvore(PONT raiz);
PONT buscaNO(PONT raiz, TIPOCHAVE ch, PONT *pai);
PONT removeNO(PONT raiz, TIPOCHAVE ch);