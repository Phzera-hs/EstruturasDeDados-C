#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>


/*Dado duas pilhas P1 e P2 que armazenam números inteiros, faça um
programa que tenha as
seguintes funções:
• Uma função para testar se as duas pilhas P1 e P2 são iguais. Caso não
forem iguais diga qual pilha é maior
• Uma função que forneça o maior, o menor e a média aritmética dos
elementos de uma pilha.
• Uma função para transferir elementos de P1 para P2 (copia).
• Uma função para retornar o número de elementos de uma pilha que
possuem valor impar.
• Uma função para retornar o número de elementos da uma pilha que
possuem valor par*/

#define MAX 5;

int Fila[MAX];
int ultimo = -1, primeiro = 0;

void enqueue(int valor){
	if(ultimo < MAX-1){
		ultimo++;
		Fila[ultimo] = valor;
		printf("Valor inserido com sucesso!");
	}
	else{
		printf("Impossivel adicionar valores");
	}
}

int dequeue(){	
	int aux;
	
}



int main(){
setlocale (LC_ALL, "");









}

