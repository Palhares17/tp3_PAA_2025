#include "../headers/cifra.h"

void executarCriptografia(int chave, char *texto, double *frequencia) {
    criptografar(chave, texto);
    printf("\nTexto criptografado: \n%s\n", texto);

    descriptografar(chave, texto);
    printf("\nTexto descriptografado: \n%s\n", texto);

    if (frequencia) {
        int chaveAdivinhada = adivinharChave(frequencia);
        printf("\nA chave chutada é: %d\nA chave verdadeira é: %d\n", chaveAdivinhada, chave);
    }
}

int tarefaB() {
    char texto[1000];

    // Leitura do texto do arquivo
    leituraArquivo(texto);
    printf("\nTexto lido: \n%s\n\n", texto);

    int escolha;
    printf("Criar chave aleatória (1) ou digitar chave (2): ");
    scanf("%d", &escolha);

    if (escolha == 1) {
        double frequencia[26];
        srand(time(NULL));
        int chave = rand() % 26;

        // Calcular frequências e criptografar
        calcularFrequencias(texto, frequencia);
        executarCriptografia(chave, texto, frequencia);

    } else if (escolha == 2) {
        int chave;
        printf("Digite a chave: ");
        scanf("%d", &chave);

        // Criptografar e descriptografar
        executarCriptografia(chave, texto, NULL);

    } else {
        printf("Opção inválida\n");
    }

    return 0;
}