#include <stdio.h>
#include <stdlib.h>
//enum declara um conjunto de variaveis começando do zero.
typedef enum { false, true } bool;
#define MAX 50

typedef int ITEM_PILHA_DUPLA;
  
typedef struct { 
    
    ITEM_PILHA_DUPLA item;

} REGISTRO;

typedef struct {
  
  REGISTRO A[MAX];
  int topo1;
  int topo2;
  
} PILHA_DUPLA;

void incializar_pilha_dupla(PILHA_DUPLA *p);
int tamanho_pilha_dupla(PILHA_DUPLA *p);
bool exibir_uma_pilha(PILHA_DUPLA *p, int pilha);
bool inserir_elemento_pilha(PILHA_DUPLA *p, REGISTRO registro, int pilha);
bool excluir_elemento_pilha(PILHA_DUPLA *p, REGISTRO *registro, int pilha);
void reiniciar_pilha(PILHA_DUPLA *p);