//Grafo BFS:
#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
typedef int TIPOPESO;


typedef struct adjacencia {
    int vertice;
    TIPOPESO peso;
    struct adjacencia *prox;
} ADJACENCIA;

typedef struct vertice {
    ADJACENCIA *cabeca;
} VERTICE;

typedef struct grafo {
    int vertices;
    int arestas;
    VERTICE *adj;
} GRAFO;

void largura(GRAFO *g);
void visitaL(GRAFO *g, int s, bool *explorou);

//Lista:
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux *proximo;
} ELEMENTO, *PONT;

typedef struct {
    PONT inicio;
    PONT fim;
} FILA;

void inicializarFila(FILA *f);
int tamanho(FILA *f);
bool inserirNaFila(FILA *f, REGISTRO reg);
bool excluirDaFila(FILA *f, REGISTRO *reg);