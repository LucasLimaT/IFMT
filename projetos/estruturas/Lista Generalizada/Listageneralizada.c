#include "Listageneralizada.h"
#include "log.h"

int addAtom(Node **list, int atom) {
    log_info("Adicionando um atomo!");
    log_trace("addAtom ->");
    Node *No = (Node *)malloc(sizeof(Node));
    if( No == NULL) 
        return -1;
    No->atomList.atom = atom;
    No->type = 0;
    No->next = NULL;
    if(*list == NULL) {
        No->next = NULL;
        *list = No;
    } else {
        Node *aux = *list;
        while(aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = No;
    }
    log_trace("addAtom <-");
    return 1;  
}

int addList(Node **list, Node **subList) {
    log_info("Adicionando lista");
    log_trace("addList <-");
    Node *No = (Node *)malloc(sizeof(Node));
    if (No == NULL)
        return -1;
    No->atomList.list = subList;
    No->type = 1;
    if (*list == NULL) {
        *list = No;
    } else {
        Node *aux = NULL;
        for (aux = *list; aux->next!=NULL; aux=aux->next);
        aux->next = No;
    }
    log_trace("addList <-");
}

Node* head(Node *list) {
    Node *headAux = NULL;
    if ((list)->type==0){
        headAux = (Node*)malloc(sizeof(Node));
        headAux->type=0;
        headAux->atomList.atom = (list)->atomList.atom;
        headAux->next=NULL;
    }else{
        headAux = list->atomList.list;
    }
    return headAux;
}

Node* tail(Node *list) {
    return (list)->next;
}

void show(Node *list) {
    log_info("Mostrado elementos na tela!");
    log_trace("show ->");
    Node *aux = NULL;
    if(list == NULL) {
        log_warn("Lista Vazia");
        log_trace("show <-");
        return;
    }else {
        for (aux = list; aux->next != NULL; aux = aux->next) {
            if (aux->type == 1) {
                printf("(");
            } else {
                printf(" %d ", aux->atomList.atom);
                show(aux);
            }
        }
        printf(")");
    }
    log_trace("show <-");
}

int depth(Node *list) {
    int contAtual = 0;
    if (list == NULL)
        return 0;
    Node *aux = list;
    if (aux->type == 0 && aux->next == NULL) {
        aux = aux->next;
    } else if(aux->type == 1 && aux->next == NULL) {
        int cont = depth(aux->atomList.list);
        if (cont>contAtual)
            contAtual = cont;
    }
    return contAtual+1;
}