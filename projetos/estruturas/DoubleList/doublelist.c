#include "doublelist.h";

void init(DoublyLinkedList *list) {
    log_info("Inicializando lista");
    log_trace("init ->");
    Node *trash = (Node *)malloc(sizeof(Node));
    trash->previous = list->first;
    trash->next = trash;
    trash->data = NULL;
    list->first = trash;
    log_trace("init <-");
}

bool isEmpty(DoublyLinkedList *list) {
    log_info("Verificando se a lista está vazia");
    log_trace("isEmpty ->");
    
}

int enqueue(DoublyLinkedList *list, void *data) {

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
