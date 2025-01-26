#include "../headers/cifra.h"

void executarCriptografia(int chave, string texto, double *frequencia) {
    int chaveAdivinhada;
    criptografar(chave, texto);

    printf("\nTexto criptografado: \n%s\n\n", texto);

    if (frequencia) {
        chaveAdivinhada = adivinharChave(frequencia);
    }

    descriptografar(chave, texto);

    if (frequencia) {
        printf("\nA chave chutada é: %d\nA chave verdadeira é: %d\n", chaveAdivinhada, chave);
    }
}

int tarefaB() {
    string texto;

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