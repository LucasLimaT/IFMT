#include "GrafoBFS.h"

void inicializarFila(FILA *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

int tamanho(FILA *f) {
    PONT end = f->inicio;
    int tam = 0;
    while (end != NULL) {
        tam++;
        end = end->proximo;
    }
    return tam;
}

bool inserirNaFila(FILA *f, REGISTRO reg) {
    PONT novo = (PONT)malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->proximo = NULL;
    if (f->inicio == NULL)
        f->inicio = novo;
    else 
        f->fim->proximo = novo;
    f->fim = novo;
    return true;
}

bool excluirDaFila(FILA *f, REGISTRO *reg) {
    if (f->inicio == NULL)
        return false;
    *reg = f->inicio->reg;
    PONT apagar = f->inicio;
    f->inicio = f->inicio->proximo;
    free(apagar);
    if (f->inicio == NULL)
        f->fim = NULL;
    return true;
}

void largura(GRAFO *g) {
    bool explorou[g->vertices];
    for (int u = 0; u < g->vertices; u++)
        explorou[u] = false;
    for (int u = 0; u < g->vertices; u++) {
        if (!explorou[u])
            visitaL(g, u, explorou);
    }
}

void visitaL(GRAFO *g, int s, bool *explorou) {
    FILA f;
    inicializarFila(&f);
    explorou[s] = true;
    REGISTRO *u = (REGISTRO *)malloc(sizeof(REGISTRO));
    u->chave = s;
    inserirNaFila(&f, *u);
    while (f.inicio) {
        excluirDaFila(&f, u);
        ADJACENCIA *v = g->adj[u->chave].cabeca;
        while (v) {
            if (!explorou[v->vertice]) {
                explorou[v->vertice] = true;
                u->chave = v->vertice;
                inserirNaFila(&f, *u);
            }
            v = v->prox;
        }
    }
    free(u);
}