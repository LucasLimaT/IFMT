#include "GrafoLista.h"

GRAFO *criagrafo(int v) {
    GRAFO *g = (GRAFO *)malloc(sizeof(GRAFO));
    g->vertice = v;
    g->arestas = 0;
    g->adj = (VERTICE *)malloc(v*sizeof(VERTICE));
    for (int i=0; i<v; i++)
        g->adj[i].cabeca = NULL;
    return(g);
}

ADJACENCIA *criaAdj(int v, int peso) {
    ADJACENCIA *temp = (ADJACENCIA *)malloc(sizeof(ADJACENCIA));
    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;
    return(temp);
}

bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p) {
    if (!gr)
        return(false);
    if ((vf<0)||(vf >= gr->vertice))
        return(false);
    if ((vi<0)||(vi >= gr->vertice))
        return(false);
    ADJACENCIA *novo = criaAdj(vf, p);
    novo->prox = gr->adj[vi].cabeca;
    gr->adj[vi].cabeca = novo;
    gr->arestas++;
    return(true);
}

void imprime(GRAFO *gr) {
    printf("Vertices: %d\nArestas: %d\n", gr->vertice, gr->arestas);
    for (int i=0; i<gr->vertice; i++) {
        printf("v%d: ", i);
        ADJACENCIA *ad = gr->adj[i].cabeca;
        while (ad) {
            printf("v%d(%d) ", ad->vertice, ad->peso);
            ad = ad->prox;
        }
        printf("\n");
    }
}