#include "Dijkstra.h"

GRAFO *criagrafo(int v) {
    GRAFO *g = (GRAFO *)malloc(sizeof(GRAFO));
    g->vertices = v;
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
    if ((vf<0)||(vf >= gr->vertices))
        return(false);
    if ((vi<0)||(vi >= gr->vertices))
        return(false);
    ADJACENCIA *novo = criaAdj(vf, p);
    novo->prox = gr->adj[vi].cabeca;
    gr->adj[vi].cabeca = novo;
    gr->arestas++;
    return(true);
}

void inicializaD(GRAFO *g, int *d, int *p, int s) {
    for (int v=0; v < g->vertices; v++) {
        d[v] = INT_MAX/2;
        p[v] = -1;
    }
    d[s] = 0; 
}

void relaxa(GRAFO *g, int *d, int *p, int u, int v) {
    ADJACENCIA *ad = g->adj[u].cabeca;
    while (ad && ad->vertice != v)
        ad = ad->prox;
    if (ad) {
        if (d[v] > d[u] + ad->peso) {
            d[v] = d[u] + ad->peso;
            p[v] = u;
        }
    }
}

bool existeAberto(GRAFO *g, int *aberto) {
    for (int i = 0; i < g->vertices; i++) {
        if (aberto[i])
            return(true);
    }
    return(false);
}

int menorDist(GRAFO *g, int *aberto, int *d) {
    int i;
    for (i = 0; i < g->vertices; i++) {
        if (aberto[i])
            break;
    }
    if (i == g->vertices)
        return(-1);
    int menor = i;
    for (i = menor+1; i < g->vertices; i++) {
        if (aberto[i] && (d[menor] > d[i]))
            menor = i;
    }
    return(menor);
}

int *dijkstra(GRAFO *g, int s) {
    int *d = (int *)malloc(g->vertices*sizeof(int));
    int p[g->vertices];
    bool aberto[g->vertices];
    inicializaD(g, d, p, s);
    for (int i = 0; i < g->vertices; i++)
        aberto[i] = true;
    while (existeAberto(g, aberto)) {
        int u = menorDist(g, aberto, d);
        aberto[u] = false;
        ADJACENCIA *ad = g->adj[u].cabeca;
        while (ad) {
            relaxa(g, d, p, u, ad->vertice);
            ad = ad->prox;
        }
    }
    return(d);
}