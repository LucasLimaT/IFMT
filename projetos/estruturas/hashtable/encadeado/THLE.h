#include <stdio.h>
#include <stdlib.h>
#define TAM 31

typedef struct no{
    int chave;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista;

void inicializarLista(Lista *l);
void inserir_na_lista(Lista *l, int valor);
int buscar_na_lista(Lista *l, int valor);
void imprimir_lista(Lista *l);
void inicializarTabela(Lista t[]);
int funcaoHash(int chave);
void inserir(Lista t[], int valor);
int busca(Lista t[], int chave);
void imprimir(Lista t[]);