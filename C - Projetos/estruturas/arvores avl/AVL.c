#include "AVL.h"

PONT CriaNO(TIPOCHAVE ch) {
    PONT novoNO = (PONT)malloc(sizeof(NO));
    novoNO->esq = NULL;
    novoNO->dir = NULL;
    novoNO->chave = ch;
    novoNO->altura_do_NO = 0;
    return(novoNO);
}

PONT inicializa() {
    return(NULL);
}

//compara qual é maior
int max(int a, int b) {
    if (a>b)
        return a;
    return b;
}

PONT direita(PONT r) {
    PONT aux;
    aux = r->esq;
    r->esq = aux->dir;
    aux->dir = r;
    
    r->altura_do_NO = max(altura(r->dir),altura(r->esq)) + 1;
    aux->altura_do_NO = max(altura(aux->esq),r->altura_do_NO) + 1;
    return(aux);
}

PONT esquerda(PONT r) {
    PONT aux;
    aux = r->dir;
    r->dir = aux->esq;
    aux->esq = r;
    
    r->altura_do_NO = max(altura(r->dir),altura(r->esq)) + 1;
    aux->altura_do_NO = max(altura(aux->dir),r->altura_do_NO) + 1;
    return(aux);
}

PONT esquerdadireita(PONT r) {
    r->esq = esquerda(r->esq);
    return(direita(r));
}
    
PONT direitaesquerda(PONT r) {
    r->dir = direita(r->dir);
    return(esquerda(r));
}

int altura (PONT raiz) {
    if (!raiz)
        return(-1);
    return(raiz->altura_do_NO);
}

PONT insere(PONT raiz, TIPOCHAVE ch) {
    if (!raiz)
        return(CriaNO(ch));
    if (ch < raiz->chave) {
        raiz->esq = insere(raiz->esq, ch);
        if ((altura(raiz->esq) - altura(raiz->dir)) == 2) {
        if (ch < raiz->esq->chave)
            raiz = direita(raiz);
        else 
            raiz = esquerdadireita(raiz);
        }
    } else {
        if (ch > raiz->chave) {
            raiz->dir = insere(raiz->dir, ch);
            if ((altura(raiz->dir) - altura(raiz->esq)) == 2) {
                if (ch > raiz->dir->chave)
                    raiz = esquerda(raiz);
                else
                    raiz = direitaesquerda(raiz);
            }
        }
    } 
    raiz->altura_do_NO = max(altura(raiz->esq), altura(raiz->dir)) + 1;
    return(raiz);
}