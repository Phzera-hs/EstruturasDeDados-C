/*
1. Crie um programa em linguagem c que receba três filas, duas j á preenchidas em ordem crescente e preencha a
ultima com os valores das duas primeiras em ordem crescente
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 5

int primeiro = 0;
int ultimo = -1;
int fila1[tam] = {2,4,6,8,10};
int fila2[tam] = {1,3,5,7,9};
int fila3[tam+tam];

int main(){

	for(int i = 0; i < tam; i++){
		printf(" [%i] ", fila1[i]);
	}
	
	printf("\n");
	
	for(int i = 0; i < tam; i++){
		printf(" [%i] ", fila2[i]);
	}
	
	for(int i = 0; i < tam; i++){
		if(fila1[i] < fila2[i])
		{
			fila1[i] = fila3[i];	 				
		}
	}
	
	for(int i = 0; i < tam; i++){
		printf(" [%i] ", fila3[i]);
	}
}
