#include "../headers/cifra.h"

void criptografar(int chave, char *texto) {
    for (int i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) {
            char letra = texto[i];
            if (islower(letra)) {
                letra = ((letra - 'a' + chave) % 26) + 'a';
            } else if (isupper(letra)) {
                letra = ((letra - 'A' + chave) % 26) + 'A';
            }
            texto[i] = letra;
        }
    }

    printf("\n\nTexto criptografado:\n%s\n\n", texto);
    escreverCifra(texto, "./cifras_criptografadas");
}

void descriptografar(int chave, char *texto) {
    lerCifra(texto);

    for (int i = 0; texto[i] != '\0'; i++) {
        if (isalpha(texto[i])) {
            char letra = texto[i];
            if (islower(letra)) {
                letra = ((letra - 'a' - chave + 26) % 26) + 'a';
            } else if (isupper(letra)) {
                letra = ((letra - 'A' - chave + 26) % 26) + 'A';
            }
            texto[i] = letra;
        }
    }

    printf("\n\nTexto descriptografado:\n%s\n\n", texto);
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

    // Contar a frequência de cada letra
    for (int i = 0; texto[i] != '\0'; i++) {
        printf("%c ", texto[i]);
        if (isalpha(texto[i])) {
            contadores[tolower(texto[i]) - 'a']++;
            total++;
        }
    }

    // Calcular porcentagem de cada letra
    for (int i = 0; i < 26; i++) {
        frequenciasCalculadas[i] = total >= 0 ? (contadores[i] / (double)total) * 100.0 : 0.0;
        if (frequenciasCalculadas[i] > 0.0) printf("\n%c: %lf\n", 'a' + i, frequenciasCalculadas[i]);
    }
}

int adivinharChave(double *frequenciasTexto) {
    double menorDiferenca = 1e9;  // Inicializar com um valor muito alto
    int chaveAdivinhada = 0;

    // Testar todas as possíveis chaves (0 a 25)
    for (int k = 0; k < 26; k++) {
        double diferencaTotal = 0.0;

        // Comparar a frequência deslocada com a tabela de frequências
        for (int i = 0; i < 26; i++) {
            int posicaoDeslocada = (i + k) % 26;
            diferencaTotal += abs(frequenciasTexto[i] - frequencias[posicaoDeslocada]);
        }

        // Atualizar a menor diferença e a chave
        if (diferencaTotal < menorDiferenca) {
            menorDiferenca = diferencaTotal;
            chaveAdivinhada = k;
        }
    }

    return chaveAdivinhada;
}
