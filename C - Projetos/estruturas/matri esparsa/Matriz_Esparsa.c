#include "Matriz_Esparsa.h"

void inicializar_Matriz(MATRIZ *m, int lin, int col) {
    m->linhas = lin;
    m->colunas = col;
    m->A = (PONT*) malloc(lin*sizeof(PONT));
    for (int i=0; i < lin; i++)
        m->A[i] = NULL;
}

bool atribui_Matriz(MATRIZ *m, int lin, int col, int val) {
    if (lin < 0 || lin >= m->linhas || col < 0 || col >= m->colunas)
        return false;
    PONT elemento_anterior = NULL;
    PONT elemento_atual = m->A[lin];
    while (elemento_atual != NULL && elemento_atual->coluna<col) {
        elemento_anterior = elemento_atual;
        elemento_atual = elemento_atual->proximo;
    }
    if (elemento_atual != NULL && elemento_atual->coluna == col) {
        if(val == 0) {
            if (elemento_anterior == NULL)
                m->A[lin] = elemento_atual->proximo;
            else 
                elemento_anterior->proximo = elemento_atual->proximo;
            free(elemento_atual);
        } else
            elemento_atual->valor = val;
    } else {
        PONT novo = (PONT) malloc(sizeof(NO));
        novo->coluna = col;
        novo->valor = val;
        novo->proximo = elemento_atual;
        if (elemento_anterior == NULL)
            m->A[lin] = novo;
        else
            elemento_anterior->proximo = novo;
    } 
    return true;
}

int valorMatriz(MATRIZ *m, int lin, int col){
    if (lin < 0 || lin >= m->linhas || col < 0 || col >= m->colunas)
        return 0;
    PONT elemento_atual = m->A[lin];
    while (elemento_atual != NULL && elemento_atual->coluna < col)
        elemento_atual = elemento_atual->proximo;
    if (elemento_atual == NULL && elemento_atual->coluna == col)
        return elemento_atual->valor;
    return 0;
}