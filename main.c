#include "headers/tarefas.h"

int main() {
    char escolha;
    printf("Qual tarefa deseja fazer A ou B? ");
    scanf("%c", &escolha);

    if (escolha == 'a') {
        tarefaA();
    } else if (escolha == 'b') {
        tarefaB();
    } else {
        printf("Escolha inválida.\n");
    }

    return 0;
}
