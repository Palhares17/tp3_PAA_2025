#include "../headers/casamento.h"

void shiftAndExato(string texto, int n, string padrao, int m) {
    int contCasamento = 0;

    long Masc[MAXCHAR], i, R = 0;

    for (i = 0; i < MAXCHAR; i++)
        Masc[i] = 0;

    for (i = 1; i <= m; i++)
        Masc[padrao[i - 1] + 127] |= 1 << (m - i);

    for (i = 0; i < n; i++) {
        R = ((((unsigned long)R) >> 1) |
             (1 << (m - 1))) &
            Masc[texto[i] + 127];
        if ((R & 1) != 0) {
            printf("Casamento na posicao %ld\n", i - m + 1);  // remover
            contCasamento++;
        }
    }
}

void forcaBruta(string texto, int n, string padrao, int m) {
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

void leituraArquivo(string texto) {
    FILE *arq;
    char nomeArq[40];
    char palavra[40];
    char caminhoArq[80] = "./arquivos/";
    int marcaPosicao = 0;

    printf("Escolha um arquivo de leitura: ");
    scanf("%s", nomeArq);

    strcat(nomeArq, ".txt");

    strcat(caminhoArq, nomeArq);

    arq = fopen(caminhoArq, "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fscanf(arq, "%s", palavra) == 1) {
        for (int i = 0; i < strlen(palavra); i++) {
            texto[marcaPosicao + i] = palavra[i];
        }
        marcaPosicao += strlen(palavra);

        // Adicionar espaço entre palavras, exceto no final
        texto[marcaPosicao] = ' ';
        marcaPosicao++;
    }

    // Remover o espaço extra no final
    if (marcaPosicao > 0) {
        texto[marcaPosicao - 1] = '\0';
    } else {
        texto[0] = '\0';  // Caso o arquivo esteja vazio
    }

    fclose(arq);
}
