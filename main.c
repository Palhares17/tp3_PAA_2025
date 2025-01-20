#include "headers/casamento.h"

int main() {
    string texto;
    string padrao;

    leituraArquivo(texto);
    printf("\nTexto lido:\n%s\n", texto);

    printf("\nDigite o nome do padrao: ");
    scanf("%s", padrao);

    printf("\nForça Bruta:\n");
    forcaBruta(texto, strlen(texto), padrao, strlen(padrao));

    printf("\nShift-And Exato:\n");
    shiftAndExato(texto, strlen(texto), padrao, strlen(padrao));

    return 0;
}
