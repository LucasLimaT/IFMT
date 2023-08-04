#define MAX 100

void countingsort(int *V, int N) {
    int baldes[MAX];
    for (int i = 0; i < MAX; i++)
        baldes[i] = 0;
    for (int i = 0; i < N; i++)
        baldes[V[i]]++;
    for (int j = 0;  j < MAX; j++) {
        int i = 0;
        for (int k = baldes[j]; k > 0; k--)
            V[i++] = j;
    }
}