#include "../headers/cifra.h"

void criptografar(int chave, char *texto) {
    char letra;

    for (int i = 0; texto[i] != '\0'; i++) {
        letra = texto[i];
        if (letra >= 'a' && letra <= 'z') {
            letra = letra + chave;
            if (letra > 'z') {
                letra = letra - 'z' + 'a' - 1;
            }
            texto[i] = letra;
        }
    }

    printf("\n\nTexto criptografado\n\n");
    escreverCifra(texto, "./cifras_criptografadas");
}

void descriptografar(int chave, char *texto) {
    char letra;

    lerCifra(texto);

    for (int i = 0; texto[i] != '\0'; i++) {
        letra = texto[i];
        if (letra >= 'a' && letra <= 'z') {
            letra = letra - chave;
            if (letra < 'a') {
                letra = letra + 'z' - 'a' + 1;
            }
            texto[i] = letra;
        }
    }

    printf("\n\nTexto descriptografado:\n%s\n", texto);
    escreverCifra(texto, "./cifras_descriptografadas");
}

void escreverCifra(char *texto, char *diretorio) {
    FILE *arq;
    char nomeArq[40];
    char caminhoArq[400];

    printf("Escolha um arquivo de escrita: ");
    scanf("%s", nomeArq);

    // Concatena o caminho do diretório, nome do arquivo e extensão
    snprintf(caminhoArq, sizeof(caminhoArq), "%s/%s.txt", diretorio, nomeArq);

    arq = fopen(caminhoArq, "w");
    if (arq == NULL) {
        printf("Erro ao criar arquivo: %s\n", caminhoArq);
        return;
    }

    fprintf(arq, "%s", texto);

    fclose(arq);
}

void lerCifra(char *texto) {
    FILE *arq;
    char nomeArq[40];
    char palavra[40];
    char caminhoArq[80] = "./cifras_criptografadas/";
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

    printf("\nTexto lido:\n%s\n", texto);

    fclose(arq);
}