#include "doublelist.h"
#include "log.h"

void init(DoublyLinkedList *list) {
    log_info("Inicializando lista");
    log_trace("init ->");
    Node *trash = (Node *)malloc(sizeof(Node));
    trash->previous = list->first;
    trash->next = trash;
    trash->data = NULL;
    list->first = trash;
    list->size = 0;
    log_trace("init <-");
}

bool isEmpty(DoublyLinkedList *list) {
    log_info("Verificando se a lista está vazia");
    log_trace("isEmpty ->");
    log_debug("list->size: (%p)", list->size);
    log_trace("isEmpty <-");
    return (list->size == 0);
}

int enqueue(DoublyLinkedList *list, void *data) {
    log_info("Enfileirando novo elemento!");
    log_trace("enqueue ->");
    Node *No = (Node *)malloc(sizeof(Node));
    Node *aux = list->next;
    if(isEmpty(list)) {
        No->previous = aux;
        aux = No;
        No->data = data;
        No->next = NULL;
        list->size += 1;
        log_debug("No(No->next, No->previous, No->data): %p(%p, %p, %p)", No, No->previous, No->next, No->data);
        log_trace("enqueue <-");
        return data;
    }
    while (aux->next != NULL) {
        aux = aux->next;
    }
    No->data = data;
    No->next = NULL;
    No->previous = aux;
    aux->next = No;
    log_debug("No(No->data, No->next, No->previous)", No, No->data, No->next, No->previous);
    list->size += 1;
    log_trace("enqueue <-");
    return data;
}

void* dequeue(DoublyLinkedList *list);
void* first(DoublyLinkedList *list);
void* last(DoublyLinkedList *list);
int push(DoublyLinkedList *list, void *data);
void* pop(DoublyLinkedList *list);
void* top(DoublyLinkedList *list);
int indexOf(DoublyLinkedList *list,void *data, compare equal);
Node* getNodeByPos(DoublyLinkedList *list,int pos);
void* getPos(DoublyLinkedList *list,int pos);
int add(DoublyLinkedList *list, int pos, void *data);
int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource);
void* removePos(DoublyLinkedList *list, int pos);
bool removeData(DoublyLinkedList *list, void *data, compare equal);
void show(DoublyLinkedList *list, printNode print);
void showMem(DoublyLinkedList *list);
