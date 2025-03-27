#include <stdio.h>
#include <stdlib.h>//Alocacao Dinamica
#include <locale.h>

typedef struct{
	char *dado;
	struct ElementoPrimitivo *seguinte;
}Elemento;

typedef struct{
	Elemento *inicio;
	int tamanho;
}Pilha;

void Init_Pilha(Pilha *pilha){
	pilha->inicio = NULL;
	pilha->tamanho = 0;
}




