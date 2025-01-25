#include "headers/tarefas.h"

int main() {
    char escolha;

    while (1) {
        printf("Qual tarefa deseja fazer A ou B?\nSair (S)\n");
        scanf("%c", &escolha);

        if (escolha == 'a' || escolha == 'A') {
            tarefaA();
        } else if (escolha == 'b' || escolha == 'B') {
            tarefaB();
        } else if (escolha == 's' || escolha == 'S') {
            break;
        } else {
            printf("Opção inválida\n");
        }

        return 0;
    }
