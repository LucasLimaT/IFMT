#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
typedef int TIPOCHAVE;

// Os dados armazenados vão aqui:
typedef struct no {
    TIPOCHAVE chave;
    struct no *filho;
    struct no *irmao;
} NO;

typedef NO *PONT;
PONT CriaNovoNO(TIPOCHAVE ch);
PONT inicializa(TIPOCHAVE ch);
PONT buscaChave(TIPOCHAVE ch, PONT raiz);
bool insere(PONT raiz, TIPOCHAVE novachave, TIPOCHAVE chavepai);
void exibirArvore(PONT raiz);