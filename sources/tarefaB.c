#include "../headers/cifra.h"

int tarefaB() {
    char texto[1000];

    leituraArquivo(texto);
    printf("\ntexto lido: \n%s", texto);
    printf("\n\n");

    int escolha;
    printf("Criar chave aleatória (1) ou digitar chave (2): ");
    scanf("%d", &escolha);

    if (escolha == 1) {
        if (escolha == 1) {
            double frequencia[26];

            srand(time(NULL));
            int chave = rand() % 26;

            calcularFrequencias(texto, frequencia);

            criptografar(chave, texto);
            printf("\nTexto criptografado: \n%s\n", texto);

            descriptografar(chave, texto);
            printf("\nTexto descriptografado: \n%s\n", texto);

            int chaveAdivinhada = adivinharChave(frequencia);
            printf("\nA chave chutada é: %d\nA chave verdadeira é: %d\n", chaveAdivinhada, chave);
        }
    } else if (escolha == 2) {
        int chave;
        printf("Digite a chave: ");
        scanf("%d", &chave);

        criptografar(chave, texto);
        descriptografar(chave, texto);
    } else {
        printf("Opção inválida\n");
    }

    return 0;
}