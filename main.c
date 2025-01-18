#include "headers/casamento.h"

int main() {
    char texto[] = "AABRAACADABRAACAADABRA";
    char padrao[] = "ACA";

    int n = strlen(texto);
    int m = strlen(padrao);

    printf("\nShift-And Exato:\n");
    shiftAndExato(texto, n, padrao, m);

    printf("\nForça Bruta:\n");
    forcaBruta(texto, n, padrao, m);

    return 0;
}