#include "../headers/casamento.h"

void shiftAndExato(char *texto, int n, char *padrao, int m) {
    int R = 0;

    // Pré-processamento do padrão
    int M[MAXCHAR];
    for (int i = 0; i < MAXCHAR; i++) {
        M[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        M[padrao[i]] |= 1 << i;
    }

    // Pesquisa
    for (int i = 0; i < n; i++) {
        R = ((R >> 1) | (1 << (m - 1))) & M[texto[i]];
        if ((R & 1) != 0) {
            printf("Casamento na posição %d\n", i - m + 1);
        }
    }
}

void forcaBruta(char *texto, int n, char *padrao, int m) {
    // Pesquisa P[0..m-1] em T[0..n-1]
    for (int i = 0; i < n - m + 1; i++) {
        int k = i;
        int j = 0;

        while ((j < m) && (texto[k] == padrao[j])) {
            j++;
            k++;
        }

        if (j == m) {
            printf("Casamento na posição %d\n", i);
        }
    }
}
