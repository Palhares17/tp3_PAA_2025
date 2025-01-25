#include "../headers/cifra.h"

void criptografar(int chave, char *texto) {
    char letra;

    for (int i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) {
            letra = texto[i];
            if (letra >= 'a' && letra <= 'z') {
                letra = letra + chave;
                if (letra > 'z') {
                    letra = letra - 'z' + 'a' - 1;
                }
                texto[i] = letra;
            }
        }
    }

    printf("\n\nTexto criptografado\n\n");
    escreverCifra(texto, "./cifras_criptografadas");
}

void descriptografar(int chave, char *texto) {
    char letra;

    lerCifra(texto);

    for (int i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) {
            letra = texto[i];
            if (letra >= 'a' && letra <= 'z') {
                letra = letra - chave;
                if (letra < 'a') {
                    letra = letra + 'z' - 'a' + 1;
                }
                texto[i] = letra;
            }
        }
    }

    printf("\n\nTexto descriptografado:\n%s\n", texto);
    escreverCifra(texto, "./cifras_descriptografadas");
}

void escreverCifra(char *texto, char *diretorio) {
    FILE *arq;
    char nomeArq[40];
    char caminhoArq[400];

    printf("\nCrie um novo arquivo de escrita: ");
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

/*----------- Frequência -----------*/
double frequencias[26] = {14.63, 1.04, 3.88, 4.99, 12.57, 1.02, 1.30, 1.28, 6.18, 0.40, 0.02, 2.78, 4.74, 5.05, 10.73, 2.52, 1.20, 6.53, 7.81, 4.34, 4.63, 1.67, 0.01, 0.21, 0.01, 0.47};

void calcularFrequencias(char *texto, double *frequenciasCalculadas) {
    int total = 0;
    int contadores[26] = {0};

    // Conta as ocorrências de cada letra
    for (int i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) {
            char letra = tolower(texto[i]);
            contadores[letra - 'a']++;
            total++;
        }
    }

    // Calcula as frequências em porcentagem
    for (int i = 0; i < 26; i++) {
        if (total > 0) {
            frequenciasCalculadas[i] = (contadores[i] / (double)total) * 100.0;
            printf("Frequencia da letra %c: %.2f\n", i + 'a', frequenciasCalculadas[i]);
        } else {
            frequenciasCalculadas[i] = 0.0;  // Evita divisão por zero
        }
    }
}

int adivinharChave(double *frequenciasTexto) {
    double menorDiferenca = 1e9;  // Inicializa com um valor grande
    int chaveAdivinhada = 0;

    for (int k = 0; k < 26; k++) {
        double diferencaTotal = 0.0;

        for (int i = 0; i < 26; i++) {
            // Calcula a posição deslocada na tabela de frequências
            int posicaoDeslocada = (i + k) % 26;
            // Soma a diferença absoluta entre frequências
            diferencaTotal += fabs(frequenciasTexto[i] - frequencias[posicaoDeslocada]);
        }

        // Atualiza se encontrar uma chave com menor diferença
        if (diferencaTotal < menorDiferenca) {
            menorDiferenca = diferencaTotal;
            chaveAdivinhada = k;
        }
    }

    return chaveAdivinhada;
}
