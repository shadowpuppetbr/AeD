#include <stdio.h>

#define MAXN 100005

int main() {
    int N, C, T;
    int P[MAXN];

    // Lê os valores de entrada: 
    // N = número de sacos de pipoca
    // C = número de competidores
    // T = limite de pipocas por segundo por competidor
    scanf("%d %d %d", &N, &C, &T);

    for (int i = 0; i < N; i++) {
        scanf("%d", &P[i]);
    }

    // Limite inferior = 1 segundo
    // Limite superior = tempo necessário se um único competidor comer tudo
    long long left = 1, right = 0;
    for (int i = 0; i < N; i++) {
        right += P[i];
    }
    right = right / T + 1; // (sum(P) // T) + 1

    while (left < right) {
        long long mid = (left + right) / 2;
        long long max_pipocas = mid * T;

        int competidores = 1;
        long long pipocas_atual = 0;
        int invalido = 0;

        for (int i = 0; i < N; i++) {
            // Se um saco sozinho já ultrapassa o limite
            if (P[i] > max_pipocas) {
                left = mid + 1;
                invalido = 1;
                break;
            }

            // Se exceder o limite atual, passa para próximo competidor
            if (pipocas_atual + P[i] > max_pipocas) {
                competidores++;
                pipocas_atual = P[i];

                if (competidores > C) {
                    left = mid + 1;
                    invalido = 1;
                    break;
                }
            } else {
                pipocas_atual += P[i];
            }
        }

        if (!invalido) {
            right = mid;
        }
    }

    printf("%lld\n", left);
    return 0;
}
