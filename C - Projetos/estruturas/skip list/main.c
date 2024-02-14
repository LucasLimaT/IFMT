#include <stdio.h>
#include "SkipList.h"

int main()
{
    SkipList *sk = criaSkipList(3, 0.5);
    liberaSkipList(sk);
    int x = insereSkipList(sk, 10);
    int z = removeSkipList(sk, 15);

    return 0;
}
