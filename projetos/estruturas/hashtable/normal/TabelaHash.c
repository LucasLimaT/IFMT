#include "TabelaHash.h"

struct hash {
    int qtd, TABLE_SIZE;
    struct aluno **itens;
};

Hash *criaHash(int TABLE_SIZE) {
    Hash *ha = (Hash*)malloc(sizeof(Hash));
    if (ha != NULL) {
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct aluno**)malloc(TABLE_SIZE * sizeof(struct aluno*));
        if (ha->itens == NULL) {
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for (int i = 0; i < ha->TABLE_SIZE; i++)
            ha->itens[i] = NULL;
    }
    return ha;
}

void liberaHash(Hash *ha) {
    if (ha != NULL) {
        for (int i = 0; i < ha->TABLE_SIZE; i++) 
            free(ha->itens[i]);
    }
    free(ha->itens);
    free(ha);
}

/*Funções de Hash:

int chaveDivisao(int chave, int TABLE_SIZE) {
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

int chaveMultiplicacao(int chave, int TABLE_SIZE){
    float A = 0.6180339887; //constante: 0 < A < 1
    float val = chave * A;
    val = val - (int) val;
    return (int) (TABLE_SIZE * val);
}

int chaveDobra(int chave, int TABLE_SIZE) {
    int num_bits = 10;
    int parte1 = chave >> num_bits;
    int parte2 = chave & (TABLE_SIZE-1);
    return (parte1 ^ parte2);
}*/

int valorString(char *str) {
    int valor = 7;
    int tam = strlen(str);
    for (int i = 0; i < tam; i++)
        valor = 31 * valor + (int) str[i];
    return valor;
}

int insereHash_semcolisao(Hash *ha, struct aluno al) {
    if (ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;
    int chave = al.matricula;
    int pos = valorString(al.nome);
    //int pos = chaveDivisao(chave, ha->TABLE_SIZE)
    struct aluno *novo;
    novo = (struct aluno*)malloc(sizeof(struct aluno));
    if (novo == NULL)
        return 0;
    *novo = al;
    ha->itens[pos] = novo;
    ha->qtd++;
    return 1;
}

int buscaHash_semcolisao(Hash *ha, int mat, struct aluno *al) {
    if (ha == NULL)
        return 0;
    int pos = valorString(al->nome);
    if (ha->itens[pos] == NULL)
        return 0;
    *al = *(ha->itens[pos]);
    return 1;
}

/*
int sondagemLinear(int pos, int i, int TABLE_SIZE) {
    return ((pos + i) & 0x7FFFFFFF) % TABLE_SIZE;
}

int sondagemQuadratica(int pos, int i, int TABLE_SIZE) {
    pos = pos + 2*i + 5*i*i;
    return (pos & 0x7FFFFFFF) % TABLE_SIZE;
}

int duploHash(int H1, int chave, int i, int TABLE_SIZE) {
    int H2 = chaveDivisao(chave, TABLE_SIZE-1) + 1;
    return ((H1 + i*H2) & 0x7FFFFFFF) % TABLE_SIZE;
}

int insereHash_enderAberto(Hash *ha, struct aluno al) {
    if (ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;
    int chave = al.matricula;
    int pos, newpos;
    pos = chaveDivisao(chave, ha->TABLE_SIZE);
    for (int i = 0; i < ha->TABLE_SIZE) {
        newpos = sondagemLinear(pos, i, ha->TABLE_SIZE);
        if (ha->itens[newpos] == NULL) {
            struct aluno *novo;
            novo = (struct aluno*)malloc(sizeof(struct aluno));
            if (novo == NULL)
                return 0;
            *novo = al;
            ha->itens[newpos] = novo;
            ha->qtd++;
            return i;
        }
    }
    return 0;
}

int buscaHash_enderAberto(Hash *ha, int mat, struct aluno *al) {
    if (ha == NULL)
        return 0;
    int pos, newpos;
    pos = chaveDivisao(mat, ha->TABLE_SIZE);
    for (int i = 0; i < ha->TABLE_SIZE; i++) {
        newpos = sondagemLinear(pos, i, ha->TABLE_SIZE);
        if (ha->itens[newpos] == NULL)
            return 0;
        if (ha->itens[newpos]->matricula == mat) {
            *al = *(ha->itens[newpos]);
            return 1;
        }
    }
    return 0;
}
*/