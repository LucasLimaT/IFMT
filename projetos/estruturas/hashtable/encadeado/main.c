#include <stdio.h>
#include <stdlib.h>
#include "THLE.h"

int main(){

    int opcao, valor, retorno;
    Lista tabela[TAM];

    inicializarTabela(tabela);

    do {
        printf("\n[0] Sair\n[1] Inserir\n[2] Buscar\n[3] Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            
            printf("\nQual valor desseja inserir? ");
            scanf("%d", &valor);
            inserir(tabela, valor);
            break;
            
        case 2:
            
            printf("\nQual valor desseja buscar? ");
            scanf("%d", &valor);
            retorno = busca(tabela, valor);
            if (retorno != 0)
                printf("Valor encontrado: %d\n", retorno);
            else
                printf("Valor nao encontrado!\n");
            break;
            
        case 3:
        
            imprimir(tabela);
            break;
            
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
