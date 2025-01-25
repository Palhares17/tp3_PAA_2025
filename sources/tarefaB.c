#include "../headers/cifra.h"

int tarefaB() {
    char texto[1000];

	leituraArquivo(texto);
    printf("\ntexto lido: \n%s", texto);
	printf("\n\n");

    criptografar(3, texto);
    descriptografar(3, texto);
    return 0;
}