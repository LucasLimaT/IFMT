#include <stdio.h>
#include <stdlib.h>

int main() {
    int *number;
    printf("Number: %p\n", &number);

    void point();
    void point2();
    void ponteiroduplo();

    return 0;
}

void point() {
    int number = 10;
    int *numberP = &number;
    printf("Valor da variavel number: %d\n", number);
    printf("Endereço da variavel number %p\n", &number);
    printf("Valor da variável numberP: %p\n", numberP);
    printf("Valor apontado por numberP: %d\n\n", *numberP);

    return;
}

void point2() {
    float *pi = (float *)malloc((sizeof(float)));
    *pi = 3,14;
    printf("\n%p", pi);
    pi=NULL;
    free(pi);
}

void ponteiroduplo() {

}