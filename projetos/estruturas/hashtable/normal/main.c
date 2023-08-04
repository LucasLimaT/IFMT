#include "TabelaHash.h"
#include <stdio.h>

int main()
{
    int mat;
    struct aluno al;
    Hash *ha = criaHash(1427);
    liberaHash(ha);
    int x = insereHash_semcolisao(ha, al);
    int z = buscaHash_semcolisao(ha, mat, &al);
    //int x = insereHash_enderAberto(ha, al);
    //int z = buscaHash_enderAberto(ha, mat, &al);

    return 0;
}
