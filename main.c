#include "headers/tarefas.h"

int main() {
    char escolha;
    printf("Qual tarefa deseja fazer A ou B? ");
    scanf("%c", &escolha);

    if (escolha == 'a' || escolha == 'A') {
        tarefaA();
    } else if (escolha == 'b' || escolha == 'B') {
        tarefaB();
    } else {
        printf("Escolha inválida.\n");
    }

    return 0;
}
