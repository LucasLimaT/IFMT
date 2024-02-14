#include <stdio.h>
#include <stdlib.h>

struct NO {
    int chave;
    struct NO **prox;
};

struct SkipList {
    int NivelMAX;
    float P;
    int nivel;
    struct NO *inicio;
};

typedef struct SkipList SkipList;
SkipList *criaSkipList(int NivelMAX, float P);
struct NO *novoNo(int chave, int nivel);
void liberaSkipList(SkipList *sk);
int buscaSkipList(SkipList *sk, int chave);
int insereSkipList(SkipList *sk, int chave);
int sorteioNivel(SkipList *sk);
int removeSkipList(SkipList *sk, int chave);