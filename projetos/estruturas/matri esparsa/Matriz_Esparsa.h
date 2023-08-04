#include <stdio.h>
#include <stdlib.h>
typedef enum { false, true } bool;

typedef struct tempNO {
    int valor;
    int coluna;
    struct tempNO *proximo;
} NO;

typedef NO *PONT;

typedef struct {
    PONT *A;
    int linhas;
    int colunas;
} MATRIZ;

void inicializar_Matriz(MATRIZ *m, int lin, int col);
bool atribui_Matriz(MATRIZ *m, int lin, int col, int valor);
int valorMatriz(MATRIZ *m, int lin, int col);