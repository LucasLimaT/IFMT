#include <stdlib.h>
#include <string.h>

struct aluno {
    int matricula;
    char nome[31];
    float n1, n2, n3;
};

typedef struct hash Hash;
Hash *criaHash(int TABLE_SIZE);
void liberaHash(Hash *ha);
/*Funções de hash:
int chaveDivisao(int chave, int TABLE_SIZE);
int chaveMultiplicacao(int chave, int TABLE_SIZE);
int chaveDobra(int chave, int TABLE_SIZE);
*/
int valorString(char *str);
int insereHash_semcolisao(Hash *ha, struct aluno al);
int buscaHash_semcolisao(Hash *ha, int mat, struct aluno *al);
/* Endereçamento aberto:
    Sondagens posiveis:
        int sondagemLinear(int pos, int i, int TABLE_SIZE);
        int sondagemQuadratica(int pos, int i, int TABLE_SIZE);
        int duploHash(int H1, int chave, int i, int TABLE_SIZE);
int insereHash_enderAberto(Hash *ha, struct aluno al);
int buscaHash_enderAberto(Hash *ha, int mat, struct aluno *al);
*/
