#include "Arvore_Binaria_Pesquisa.h"

PONT inicializa(){
    return(NULL);
}

PONT CriaNovoNo(TIPOCHAVE ch){
    PONT novoNo = (PONT)malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    return(novoNo);
}

PONT adiciona(PONT raiz, PONT no) {
    if (raiz == NULL)
        return(no);
    if (no->chave < raiz->chave)
        raiz->esq = adiciona(raiz->esq, no);
    else
        raiz->dir = adiciona(raiz->dir, no);
    return(raiz);
}

PONT contem(TIPOCHAVE ch, PONT raiz) {
    if (raiz == NULL)
        return(NULL);
    if (raiz->chave ==  ch)
        return(raiz);
    if (raiz->chave > ch)
        return(contem(ch, raiz->esq));
    return(contem(ch, raiz->dir));
}

int numeroNos(PONT raiz) {
    if (!raiz)
        return 0;
    return(numeroNos(raiz->esq)+1+numeroNos(raiz->dir));
}

void ExibirArvore(PONT raiz) {
    if (raiz != NULL) {
        printf("%d", raiz->chave);
        printf("(");
        ExibirArvore(raiz->esq);
        ExibirArvore(raiz->dir);
        printf(")");
    }
}

PONT buscaNO(PONT raiz, TIPOCHAVE ch, PONT *pai) {
    PONT atual = raiz;
    *pai = NULL;
    while (atual) {
        if (atual->chave == ch)
            return(atual);
        *pai = atual;
        if (ch < atual->chave)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return(NULL);
}

PONT removeNO(PONT raiz, TIPOCHAVE ch) {
    PONT pai, no, p, q;
    no = buscaNO(raiz, ch, &pai);
    if (no == NULL)
        return(raiz);
    if (!no->esq || !no->dir) {
        if (!no->esq)
            q = no->dir;
        else
            q= no->esq;
    } else {
        p = no;
        q = no->esq;
        while(q->dir) {
            p = q;
            q = q->dir;
        }
        if (p != no) {
            p->dir = q->esq;
            q->esq = no->esq;
        }
        q->dir = no->dir;
    } if (!pai) {
        free(no);
        return(q);
    } if (ch < pai->chave)
        pai->esq = q;
    else
        pai->dir = q;
    free(no);
    return(raiz);
        
}