#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXCHAR 256

typedef char string[1000];

void forcaBruta(string texto, int n, string padrao, int m);
void shiftAndExato(string texto, int n, string padrao, int m);

void leituraArquivo(string texto);
