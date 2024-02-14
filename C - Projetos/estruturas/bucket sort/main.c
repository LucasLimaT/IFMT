#define TAM 5
struct balde {
    int qtd;
    int valores[TAM];
};

void bucketsort(int *V, int N) {
    int maior, menor, nroBalde, pos;
    struct balde *bd;
    maior = menor = V[0];
    for (int i = 1; i < N; i++) {
        if (V[i] > maior)
            maior = V[i];
        if (V[i] < menor)
            menor = V[i];
    }
    nroBalde = (maior - menor) / TAM + 1;
    bd = (struct balde*)malloc(nroBalde * sizeof(struct balde));
    for (int i = 0; i < nroBalde; i++)
        bd[i].qtd = 0;
    for (int i = 0; i < N; i++) {
        pos = (V[i] - menor) / TAM;
        bd[pos].valores[bd[pos].qtd] = V[i];
        bd[pos].qtd++;
    }
    pos = 0;
    for (int i = 0; i < nroBalde; i++) {
        insertionSort(bd[i].valores, bd[i].qtd);
        for (int j = 0; j < bd[i].qtd; j++) {
            V[pos] = bd[i].valores[j];
            pos++;
        }
    }
    free(bd);
}