#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>


/*Dado duas pilhas P1 e P2 que armazenam n�meros inteiros, fa�a um
programa que tenha as
seguintes fun��es:
� Uma fun��o para testar se as duas pilhas P1 e P2 s�o iguais. Caso n�o
forem iguais diga qual pilha � maior
� Uma fun��o que forne�a o maior, o menor e a m�dia aritm�tica dos
elementos de uma pilha.
� Uma fun��o para transferir elementos de P1 para P2 (copia).
� Uma fun��o para retornar o n�mero de elementos de uma pilha que
possuem valor impar.
� Uma fun��o para retornar o n�mero de elementos da uma pilha que
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

