#include "doublelist.h"
#include "log.h"

void init(DoublyLinkedList *list) {
    log_info("Inicializando lista");
    log_trace("init ->");
    Node *trash = (Node *)malloc(sizeof(Node));
    trash->previous = trash;
    trash->next = trash;
    trash->data = NULL;
    list->first = trash;
    list->size = 0;
    log_debug("trash(trash->data, trash->next, trash->previous): %p(%p, %p, %p)", trash, trash->data, trash->next, trash->previous);
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
    Node *aux = list->first->previous;
    aux->next = list->first;
    No->data = data;
    No->next = aux->next;
    No->previous = aux;
    log_debug("No ( No->data, No->next, No->previous): %p ( %p, %p, %p)", No, No->data, No->next, No->previous);
    list->size += 1;
    log_trace("enqueue <-");
    return 1;
}

void* dequeue(DoublyLinkedList *list) {
    log_info("Retirando valor da fila!");
    log_trace("dequeue ->");
    if (isEmpty(list)) {
        log_warn("A lista está vazia!");
        log_trace("dequeue <-");
        return NULL; 
    }
    Node *aux = list->first->next;
    log_debug("aux(aux->next, aux->previous, aux->data)", aux, aux->next, aux->previous, aux->data);
    void *data = list->first->data;
    log_debug("data: %p", data);
    list->first = aux;
    free(aux);
    list->size -= 1;
    log_trace("dequeue <-");
    return data;
}

void* first(DoublyLinkedList *list) {
    log_info("informando primeiro valor da lista!");
    log_trace("first ->");
    if (isEmpty(list)) {
        log_warn("não há elementos na lista!");
        log_trace("first <-");
        return NULL;
    }
    log_trace("first <-");
    return list->first;
}

/*void* last(DoublyLinkedList *list);
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
void showMem(DoublyLinkedList *list);*/
