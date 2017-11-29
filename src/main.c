#include <stdio.h>

#define MAX 500

int ehNumero(char c) {
	return ((int)c >= 48 && (int)c <= 57);
}

int ehLetra(char c) {
	return (((int)c >= 65 && (int)c <= 90) || ((int)c >= 97 && (int)c <= 122));
}

int ehSeparador(char c) {
	return ((int)c == '.' || (int)c == ',');
}


int main() {
	char frase[MAX];

	gets(frase);

	int palavras = 0;

	int ultimoFoiLetra = 0;
	int ultimoFoiNumero = 0;
	int ultimoFoiSeparador = 0;

	for (int i=1; frase[i] != '\0' && i<MAX; i++) {

		if (ehLetra(frase[i]) && !ultimoFoiLetra) {
			ultimoFoiLetra = 1;
			palavras++;
		}

		if (!ehLetra(frase[i])) ultimoFoiLetra = 0;
		else ultimoFoiLetra = 1;

		if (ehNumero(frase[i]) && !ultimoFoiNumero && !ultimoFoiSeparador) {
			ultimoFoiNumero = 1;
			palavras++;
		}

		if (!ehNumero(frase[i])) ultimoFoiNumero = 0;
		else ultimoFoiNumero = 1;

		if (ehSeparador(frase[i])) ultimoFoiSeparador = 1;
		else ultimoFoiSeparador = 0;

	}

	printf("%d\n", palavras);
	return 0;
}