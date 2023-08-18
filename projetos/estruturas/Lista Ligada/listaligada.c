#include <stdio.h>
#include <stdlib.h>
#include "listaligada.h"
#include "log.h"

void init(LinkedList *list) {
    log_info("iniciando a lista");
    log_trace("init ->");
    list->first = NULL;
    list->size = 0;
    log_debug("list->first: %p", list->first);
	log_debug("list->size: %d", list->size);
    log_trace("init <-");
}

bool isEmpty(LinkedList *list) {
    log_trace("isEmpty ->")
    if(list == NULL) {
        log_error("Deu erro, você quer adicionar algo em algo que não existe!");
        log_debug("list: %p", list);
        return true;
    }
    log_debug("list->size: %d",list->size);
    log_trace("isEmpty <-");
    return (list->size == 0) ? true:false ;
}

int enqueue(LinkedList *list, void *data) {
    log_info("Adicionando em fila na lista");
    Node *no = (Node *)malloc(sizeof(Node));
    log_debug()
    
}

void* dequeue(LinkedList *list) {

}

void* first(LinkedList *list) {

}

void* last(LinkedList *list) {

}

int push(LinkedList *list, void *data) {

}

void* pop(LinkedList *list) {

}

void* top(LinkedList *list) {

}


int indexOf(LinkedList *list, void *data, compare equal) {

}

void* getPos(LinkedList *list, int pos) {

}

Node* getNodeByPos(LinkedList *list, int pos) {

}

int add(LinkedList *list, int pos, void *data) {

}

int addAll(LinkedList *listDest, int pos, LinkedList *listSource) {

}

void* removePos(LinkedList *list, int pos) {

}

bool removeData(LinkedList *list, void *data, compare equal) {

}