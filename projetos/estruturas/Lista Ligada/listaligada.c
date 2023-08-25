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
    log_info("Verificando se a lista está vazia");
    log_trace("isEmpty ->");
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
    log_trace("enqueue ->");
    Node *no = (Node *)malloc(sizeof(Node));
    if (no == NULL) {
        log_debug("no: %p", no);
        log_error("Memoria insuficiente para operação!");
        log_trace("enqueue <-");
        return 0;
    } else {
        no->data = data;
        no->next = NULL;
    }    
    if (isEmpty(list)) {
        list->first = no;
    } else {
        Node *aux = list->first;
        log_debug("(aux, aux->next): (%p, %p)", aux, aux->next);
        while(aux->next != NULL) {
            aux = aux->next;
            log_debug("(aux, aux->next): (%p, %p)", aux, aux->next);
        }
        aux->next = no;
        log_debug("(aux, aux->next): (%p, %p)", aux, aux->next);
    }
    list->size += 1;        
    log_debug("no(data, next): %p(%p, %p)", no, no->data, no->next);
    log_info("Dado inserido com sucesso!");
    log_trace("enqueue <-");
    return 1;
}

void* dequeue(LinkedList *list) {
    log_info("Retirando valor da fila");
    log_trace("dequeue ->");
    if(isEmpty(list)) {
        log_error("A lista está vazia");
        log_trace("dequeue <-");
        return (NULL);
    } else {
        Node *aux = list->first;
        log_debug("(list->first->data, list->first->next), (%p, %p)", list->first->data, list->first->next);
        list->first = list->first->next;
        list->size -= 1;
        log_trace("dequeue <-");
        void *data = aux->data;
        free(aux);
        return data;
    }
}

void* first(LinkedList *list) {
    log_info("Pegando primeiro nó da lista");
    log_trace("first ->");
    if (isEmpty(list)) {
        log_warn("A lista está vazia");
        log_trace("first <-");
        return NULL;
    } 
    log_debug("list->first: %p", list->first);
    log_trace("first <-");
    return list->first;
}

void* last(LinkedList *list) {
    log_info("Pegando ultimo nó da lista");
    log_trace("last ->");
    if (isEmpty(list)) {
        log_warn("A lista está vazia");
        log_trace("last <-");
        return NULL;
    }
    Node *aux = list->first;
    log_debug("aux(aux->next, aux->data): %p(%p, %p)", aux, aux->next, aux->data);
    while(aux->next != NULL) {
        aux = aux->next;
        log_debug("aux(aux->next, aux->data): %p(%p, %p)", aux, aux->next, aux->data);
    }
    log_trace("last <-");
    return aux->data;
}

int push(LinkedList *list, void *data) {
    log_info("Insere na pilha");
}

void* pop(LinkedList *list) {
    log_info("Removendo o topo da pilha");
    log_trace("pop ->");
    Node *data = dequeue(list);
    log_trace("pop <-");
    return data;
}

void* top(LinkedList *list) {
    log_info("Consultando o topo da pilha");
    log_trace("top ->");
    Node *data = first(list);
    log_trace("top <-");
    return data;
}


/*int indexOf(LinkedList *list, void *data, compare equal) {
    
}*/

void* getPos(LinkedList *list, int pos) {
    return NULL;
}

Node* getNodeByPos(LinkedList *list, int pos) {
    return NULL;
}

int add(LinkedList *list, int pos, void *data) {
    return 0;
}

int addAll(LinkedList *listDest, int pos, LinkedList *listSource) {
    return 0;
}

void* removePos(LinkedList *list, int pos) {
    return NULL;
}

bool removeData(LinkedList *list, void *data, compare equal) {
    return false;
}                                        