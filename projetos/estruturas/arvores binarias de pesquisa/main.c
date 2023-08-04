#include <stdio.h>
#include <stdlib.h>
#include "Arvore_Binaria_Pesquisa.h"

int main()
{
    PONT r = inicializa();
    //no caso o 23 poderia ser qualquer número, ele só ta criando um nó para o 23.
    PONT no = CriaNovoNo(23);
    r = adiciona(r, no);
    //procura o 12 na arvore.
    PONT p = contem(12, r);
    printf("%d\n", numeroNos(r));
    ExibirArvore(r);

    return 0;
}
