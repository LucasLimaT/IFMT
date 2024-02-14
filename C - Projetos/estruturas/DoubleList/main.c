#include <stdio.h>
#include <stdlib.h>
#include "doublelist.h"
#include "log.h"

int main() {
    FILE *fp = fopen("Doublelist.log", "w");
    log_set_level(LOG_INFO);
    log_add_fp(fp, LOG_TRACE);

    DoublyLinkedList list;
    init(&list);
    enqueue(&list, 20);
    

    return 0;
}