#include <stdio.h>
#include <stdlib.h>

// Função de comparação para qsort (ordem decrescente)
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int hIndex(int* citations, int citationsSize) {
    // Ordena em ordem decrescente
    qsort(citations, citationsSize, sizeof(int), compare);

    int h = 0;
    for (int i = 0; i < citationsSize; i++) {
        if (citations[i] >= i + 1) {
            h++;
        } else {
            break;
        }
    }
    return h;
}

int main() {
    int citations[] = {3, 0, 6, 1, 5};
    int n = sizeof(citations) / sizeof(citations[0]);

    int h = hIndex(citations, n);
    printf("H-Index: %d\n", h);  // Saída esperada: 3

    return 0;
}
