#include "SkipList.h"

SkipList *criaSkipList(int NivelMAX, float P) {
    SkipList *sk = (SkipList*)malloc(sizeof(SkipList));
    if (sk != NULL) {
        sk->NivelMAX = NivelMAX;
        sk->P = P;
        sk->nivel = 0;
        sk->inicio = novoNo(-1, NivelMAX);
    }
    return sk;
}

struct NO *novoNo(int chave, int nivel) {
    struct NO *novo = malloc(sizeof(struct NO));
    if (novo != NULL) {
        novo->chave = chave;
        novo->prox = malloc((nivel+1) * sizeof(struct NO*));
        for (int i = 0; i < (nivel+1); i++)
            novo->prox[i] = NULL;
    }
    return novo;
}

void liberaSkipList(SkipList *sk) {
    if (sk == NULL)
        return;
    struct NO *no, *atual;
    atual = sk->inicio->prox[0];
    while (atual != NULL) {
        no = atual;
        atual = atual->prox[0];
        free(no->prox);
        free(no);
    }
    free(sk->inicio);
    free(sk);
}

int buscaSkipList(SkipList *sk, int chave) {
    if (sk == NULL)
        return 0;
    struct NO *atual = sk->inicio;
    for (int i = sk->nivel; i >= 0; i--) {
        while (atual->prox[i] != NULL && atual->prox[i]->chave < chave)
            atual = atual->prox[i];
    }
    atual = atual->prox[0];
    if (atual != NULL && atual->chave == chave)
        return 1;
    else
        return 0;
}

int insereSkipList(SkipList *sk, int chave) {
    if (sk == NULL)
        return 0;
    struct NO *atual = sk->inicio;
    struct NO **aux;
    aux = malloc((sk->NivelMAX+1) * sizeof(struct NO*));
    for (int i = 0; i <= sk->NivelMAX; i++)
        aux[i] = NULL;
    for (int i = sk->nivel; i >= 0; i--) {
        while (atual->prox[i] != NULL && atual->prox[i]->chave < chave)
            atual = atual->prox[i];
        aux[i] = atual;
    }
    atual = atual->prox[0];
    if (atual == NULL || atual->chave != chave) {
        int novo_nivel = sorteioNivel(sk);
        struct NO *novo = novoNo(chave, novo_nivel);
        if (novo == NULL) {
            free(aux);
            return 0;
        }
        if (novo_nivel > sk->nivel) {
            for (int i = sk->nivel+1; i <= novo_nivel; i++)
                aux[i] = sk->inicio;
            sk->nivel = novo_nivel;
        }
        for (int i = 0; i <= novo_nivel; i++) {
            novo->prox[i] = aux[i]->prox[i];
            aux[i]->prox[i] = novo;
        }
        free(aux);
        return 1;
    }
}

int sorteioNivel(SkipList *sk) {
    float r = (float)rand()/RAND_MAX;
    int nivel = 0;
    while (r < sk->P && nivel < sk->NivelMAX) {
        nivel++;
        r = (float)rand()/RAND_MAX;
    }
    return nivel;
}

int removeSkipList(SkipList *sk, int chave) {
    if (sk == NULL)
        return 0;
    struct NO *atual = sk->inicio;
    struct NO **aux;
    aux = malloc((sk->NivelMAX+1) * sizeof(struct NO*));
    for (int i = 0; i <= sk->NivelMAX; i++)
        aux[i] = NULL;
    for (int i = sk->nivel; i >=0; i--) {
        while (atual->prox[i] != NULL && atual->prox[i]->chave < chave)
            atual = atual->prox[i];
        aux[i] = atual;
    }
    atual = atual->prox[0];
    if (atual != NULL && atual->chave == chave) {
        for (int i = 0; i <= sk->nivel; i++) {
            if (aux[i]->prox[i] != atual)
                break;
            aux[i]->prox[i] = atual->prox[i];
        }
        while (sk->nivel > 0 && sk->inicio->prox[sk->nivel] == NULL)
            sk->nivel--;
        free(atual->prox);
        free(atual);
        free(aux);
        return 1;
    }
    free(aux);
    return 0;
}