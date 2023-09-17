#include "Listageneralizada.h"
#include "log.h"

int addAtom(Node **list, int atom) {
    log_info("Adicionando um atomo!");
    log_trace("addAtom ->");
    Node *No = (Node *)malloc(sizeof(Node));
    No->atomList.atom = atom;
    No->type = 0;
    if(*list == NULL) {
        No->next = NULL;
        *list = No
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
    
}

void show(Node *list) {
    log_info("Mostrado elementos na tela!");
    log_trace("show ->");
    Node *aux = list;
    if(*list == NULL) {
        log_warn("Lista Vazia");
        log_trace("show <-");
        return;
    } do {
        if(aux->type == 1) {
            while(aux->type == 1){
                printf("(");
                aux = aux->next;
            }
        } else if(aux->type == 0) {
            while(aux->type == 0){
                printf("%d", aux->atomList.atom);
                aux = aux->next;
            } while(aux->type == 1) {
                printf(")");
                aux = aux->next;
            }
        }
    } while(aux->next != NULL);
    log_trace("show <-");
    return;
}