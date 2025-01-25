#include "includes.h"

void criptografar(int chave, char *texto);
void descriptografar(int chave, char *texto);
void lerCifra(char *texto);
void escreverCifra(char *texto, char *diretorio);

void calcularFrequencias(char *texto, double *frequencia);
int adivinharChave(double *frequencias);