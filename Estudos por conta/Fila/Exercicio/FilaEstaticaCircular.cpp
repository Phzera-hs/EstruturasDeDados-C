#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>


/*Implemente uma fila circular com capacidade para 5 inteiros. Seu programa deve permitir:

Inserir elemento na fila

Remover elemento da fila

Mostrar todos os elementos da fila

Mostrar o primeiro e o último elemento

Mostrar a quantidade de elementos atuais

Encerrar o programa*/

#define MAX 10

typedef struct{
	int quantidade;
	int elementos[MAX];
	int inicio;
	int final;
}Fila;


void InitFila(Fila *fi) {
    fi->inicio = 0;
    fi->final = 0;
    fi->quantidade = 0;
}

bool isEmpty(Fila *fi){
	return fi->quantidade == 0;
}
bool isFull(Fila *fi){
	 return fi->quantidade == MAX;
}


void enqueue(Fila *fi, int valor){
    if (isFull(fi)) {
        printf("Fila cheia!\n");
        return;
    }
    fi->elementos[fi->final] = valor;
    fi->final = (fi->final + 1) % MAX;
    fi->quantidade++;
}

int dequeue(Fila *fi){
  if (isEmpty(fi)) {
        printf("Fila vazia!\n");
        return -1;
    }
    int valor = fi->elementos[fi->inicio];
    fi->inicio = (fi->inicio + 1) % MAX;
    fi->quantidade--;
    return valor;
}


void listagem(Fila *fi){
	printf("\n---Elementos da fila---\n");
	int i = fi->inicio;
	for(int c = 0; c < fi->quantidade; c++){
		printf("[%i]", fi->elementos[i]);
		i = (i + 1) % MAX;
	}
	 printf("\n");
}

void FirtsOrLast(Fila *fi){
	int escolha;
	printf("Escolher\nPrimeiro[1]\nUltimo[2]");
	scanf("%i", &escolha);
	
	if(escolha == 1){
		if(!isEmpty(fi)){
			printf("Primeiro = %i", fi->elementos[fi->inicio]);
		}
	}
	else if(escolha == 2){
		if(!isEmpty(fi)){
			printf("Ultimo = %i", fi->elementos[fi->final]);
		}
	}	
	else{
		printf("Escolha incorreta!");
	}
}
int contaElementos(Fila *fi){
	int conta = 0;
	for(int i = 0; i < fi->final; i++){
		conta++;
	}
	return conta;
}

int main(){
setlocale (LC_ALL, "");
	
	Fila fi;
	
	InitFila(&fi);

	int opcao, valor;
	
	do{
		printf("\n======= MENU FILA =======\n");
		printf("1 - Inserir da fila\n");
		printf("2 - Remover da fila\n");
		printf("3 - Listagem da fila\n");
		printf("4 - Primeiro ou ultimo elemento da fila\n");
		printf("5 - Conta elementos\n");
		printf("6 - Encerrar\n");
		printf("Escolha: ");
		scanf("%d", &opcao);
	
		switch (opcao) {
		case 1:
			printf("Digite o valor que deseja inserir: ");
			scanf("%i", &valor);
			enqueue(&fi, valor);
		break;
		case 2:
			valor = dequeue(&fi);
		break;
		case 3:
			listagem(&fi);
		break;
		case 4:
			FirtsOrLast(&fi);
		break;
		case 5:
			valor = contaElementos(&fi);
			printf("Quantidade de elementos %i\n", valor);
		break;
		default:
			printf("Opção incorreta!");
		break;
		}
	}while(opcao != 6);
}





