#include "GrafoDeepSearch.h"

void profundidade(GRAFO *g) {
    int cor[g->vertices];
    for (int u = 0; u < g->vertices; u++)
        cor[u] = BRANCO;
    for (int u = 0; u < g->vertices; u++) {
        if (cor[u] == BRANCO)
            visitaP(g, u, cor);
    }
}

void visitaP(GRAFO *g, int u, int *cor) {
    cor[u] = AMARELO;
    ADJACENCIA *v = g->adj[u].cabeca;
    while (v) {
        if (cor[v->vertice] == BRANCO)
            visitaP(g, v->vertice, cor);
        v = v->prox;
    }
    cor[u] = VERMELHO;
}