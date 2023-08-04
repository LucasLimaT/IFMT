#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
typedef int TIPOPESO;

typedef struct grafo {
    int vertices;
    int arestas;
    TIPOPESO **adj;
} GRAFO;