#include "../headers/casamento.h"

int tarefaA() {
    string texto;
    string padrao;

    clock_t tempo;  // variavel que armazenará o tempo de execução

    leituraArquivo(texto);
    printf("\nTexto lido:\n%s\n", texto);

    printf("\nDigite o nome do padrao: ");
    scanf("%s", padrao);

    int escolha;
    do {
        printf("Escolha entre Shift-And Exato (1) e Força Bruta (2): ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            printf("\nShift-And Exato:\n");

            tempo = clock();
            shiftAndExato(texto, strlen(texto), padrao, strlen(padrao));
            tempo = clock() - tempo;

            printf("Tempo de execucao: %lf\n\n", ((double)tempo) / ((CLOCKS_PER_SEC / 1000)));

        }

        else if (escolha == 2) {
            printf("\nForça Bruta:\n");

            tempo = clock();
            forcaBruta(texto, strlen(texto), padrao, strlen(padrao));
            tempo = clock() - tempo;

            printf("Tempo de execucao: %lf\n\n", ((double)tempo) / ((CLOCKS_PER_SEC / 1000)));
        }
    } while (escolha == 1 || escolha == 2);
    return 0;
}