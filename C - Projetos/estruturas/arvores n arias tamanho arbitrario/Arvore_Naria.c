#include "Arvore_Naria.h"

PONT CriaNovoNO(TIPOCHAVE ch) {
    PONT novo = (PONT)malloc(sizeof(NO));
    novo->filho = NULL;
    novo->irmao = NULL;
    novo->chave = ch;
    return(novo);
}

PONT inicializa(TIPOCHAVE ch) {
    return(CriaNovoNO(ch));
}

PONT buscaChave(TIPOCHAVE ch, PONT raiz) {
    if (raiz == NULL)
        return NULL;
    if (raiz->chave == ch)
        return raiz;
    PONT ponteiro = raiz->filho;
    while (ponteiro) {
        PONT resposta = buscaChave(ch, ponteiro);
        if (resposta)
            return(resposta);
        ponteiro = ponteiro->irmao;
    }
    return(NULL);
}

bool insere(PONT raiz, TIPOCHAVE novachave, TIPOCHAVE chavepai) {
    PONT pai = buscaChave(chavepai, raiz);
    if (!pai)
        return(false);
    PONT novo_filho = CriaNovoNO(novachave);
    PONT ponteiro = pai->filho;
    if (!ponteiro)
        pai->filho = novo_filho;
    else {
        while (ponteiro->irmao)
            ponteiro = ponteiro->irmao;
        ponteiro->irmao = novo_filho;
    }
    return(true);
}

void exibirArvore(PONT raiz) {
    if (raiz == NULL)
        return;
    printf ("%d(", raiz->chave);
    PONT ponteiro = raiz->filho;
    while (ponteiro) {
        exibirArvore(ponteiro);
        ponteiro = ponteiro->irmao;
    }
    printf (")");
}