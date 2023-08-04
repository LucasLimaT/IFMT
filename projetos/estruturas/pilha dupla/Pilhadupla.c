#include "Pilhadupla.h"

void incializar_pilha_dupla(PILHA_DUPLA *p) {
    p->topo1 = -1;
    p->topo2 = MAX;
}

int tamanho_pilha_dupla(PILHA_DUPLA *p) {
    return p->topo1+1 + MAX - p->topo2;
}

bool exibir_uma_pilha(PILHA_DUPLA *p, int pilha) {
    if (pilha < 1 || pilha > 2) 
        return false;
    printf("Pilha %d: \" ", pilha);
    if (pilha == 1) {
        for (int i = p->topo1; i >= 0; i--)
            printf("%d ", p->A[i].item);
    } else {
        for (int i = p->topo2; i < MAX; i++)
            printf("%d ", p->A[i].item);
    } 
    return true;
}

bool inserir_elemento_pilha(PILHA_DUPLA *p, REGISTRO registro, int pilha) {
    if (pilha < 1 || pilha > 2)
        return false;
    if (p->topo1 + 1 == p->topo2)
        return false;
    if (pilha == 1) {
        p->topo1 = p->topo1 + 1;
        p->A[p->topo1] = registro;
    } else {
        p->topo2 = p->topo2 - 1;
        p->A[p->topo2] = registro;
    }
}

bool excluir_elemento_pilha(PILHA_DUPLA *p, REGISTRO *registro, int pilha) {
    if (pilha < 1 || pilha > 2)
        return false;
    if (pilha == 1) {
        if(p->topo1 == 1)
            return false;
        *registro = p->A[p->topo1];
        p->topo1 = p->topo1 - 1;
    } else {
        if(p->topo2 == MAX)
            return false;
        *registro = p->A[p->topo2];
        p->topo2 = p->topo2 + 1;
    }
    return true;
}

void reiniciar_pilha(PILHA_DUPLA *p) {
    p->topo1 = -1;
    p->topo2 = MAX;
    incializar_pilha_dupla(p);
}