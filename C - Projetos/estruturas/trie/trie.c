#include "trie.h"

PONT criaNO() {
    PONT ponteiro = NULL;
    ponteiro = (PONT)malloc(sizeof(NO));
    if (ponteiro) {
        ponteiro->fim = false;
        for (int i = 0; i < N_ALFABETO; i++)
            ponteiro->filhos[i] = NULL;
    }
    return(ponteiro);
}

PONT inicializa() {
    return(criaNO());
}

int mapearIndice(char c) {
    return((int)c - (int)'a');
}

void insere(PONT raiz, char *chave) {
    int comprimento = strlen(chave);
    PONT ponteiro = raiz;
    for (int nivel = 0; nivel < comprimento; nivel++) {
        int i = mapearIndice(chave[nivel]);
        if (!ponteiro->filhos[i])
            ponteiro->filhos[i] = criaNO();
        ponteiro = ponteiro->filhos[i];
    }
    ponteiro->fim = true;
}

bool busca(PONT raiz, char *chave) {
    int comprimento = strlen(chave);
    PONT ponteiro = raiz;
    for (int nivel = 0; nivel < comprimento; nivel++) {
        int i = mapearIndice(chave[nivel]);
        if (!ponteiro->filhos[i])
            return(false);
        ponteiro = ponteiro->filhos[i];
    }
    return(ponteiro->fim);
}