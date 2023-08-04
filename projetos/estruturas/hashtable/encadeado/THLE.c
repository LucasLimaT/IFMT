#include "THLE.h"

void inicializarLista(Lista *l){
    l->inicio = NULL;
    l->tam = 0;
}

void inserir_na_lista(Lista *l, int valor){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->chave = valor;
        novo->proximo = l->inicio;
        l->inicio = novo;
        l->tam++;
    }
    else
        printf("\n\tErro ao alocar memoria!\n");
}

int buscar_na_lista(Lista *l, int valor){
    No *aux = l->inicio;
    while(aux && aux->chave != valor)
        aux = aux->proximo;
    if(aux)
        return aux->chave;
    return 0;
}

void imprimir_lista(Lista *l){
    No *aux = l->inicio;
    printf(" Tam: %d: ", l->tam);
    while(aux){
        printf("%d ", aux->chave);
        aux = aux->proximo;
    }
}

void inicializarTabela(Lista t[]){
    int i;

    for(i = 0; i < TAM; i++)
        inicializarLista(&t[i]);
}

int funcaoHash(int chave){
    return chave % TAM;
}

void inserir(Lista t[], int valor){
    int id = funcaoHash(valor);
    inserir_na_lista(&t[id], valor);
}

int busca(Lista t[], int chave){
    int id = funcaoHash(chave);
    return buscar_na_lista(&t[id], chave);
}

void imprimir(Lista t[]){
    int i;
    for(i = 0; i < TAM; i++){
        printf("%2d = ", i);
        imprimir_lista(&t[i]);
        printf("\n");
    }
}