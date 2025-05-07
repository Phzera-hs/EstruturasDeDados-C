#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>


/*Faça um programa que apresente o menu de opções abaixo:
MENU
1- Cadastrar número
2- Mostrar números pares
3- Excluir número
4- Sair
Observações:
a) O programa deve ser implementado usando uma estrutura do tipo pilha
b) A opção 1 do menu cadastra um número de cada vez.
c) Mostrar mensagem para opção inválida do menu
d) Mostrar mensagem para opção invalidade do menu.
e) Quando a opção do menu não puder ser realizada, mostrar mensagem*/



typedef struct{

	int *Elementos;
	int tamanho;
	int topo;


}Pilha;

void initPilha(Pilha *p, int MIN){
	p->Elementos = (int *)malloc(MIN * sizeof(int));
	p->tamanho = MIN;
	p->topo = -1;
}

void push(Pilha *p, int valor){
	if(p->topo <= p->tamanho-1){
		p->topo++;
		if(p->topo >= p->tamanho - 1){
		p->tamanho*=2;
		p->Elementos = (int *)realloc(p->Elementos,p->tamanho*sizeof(int));
		}
		p->Elementos[p->topo] = valor;
	}
	else{
		printf("[PUSH-ERROR]\nNão é possivel adicionar o valor!");
	}
}

void pop(Pilha *p){
	int aux;
	if(p->topo >= 0){	
		aux = p->Elementos[p->topo];
		p->topo--;
		printf("Valor %i removido com sucesso!", aux);
	}else{
		printf("[POP-ERROR]\nNão é possivel remover o valor!");
	}
}

void listaFull(Pilha *p){
	if(p->topo >= 0){
		printf("--- LISTA FULL ---\n");
		for(int i = 0; i <= p->topo; i++){
			printf("[%i]\n", p->Elementos[i]);
		}
	}else{
		printf("[LISTAFULL-ERROR]\nNão é possivel mostrar toda pilha!");
	}
}

void listaPar(Pilha *p){
	if(p->topo >= 0){
		printf("--- LISTA FULL ---\n");
		for(int i = 0; i <= p->topo; i++){
			if(p->Elementos[i] % 2 == 0){
				printf("[%i]\n", p->Elementos[i]);
			}
		}
	}else{
		printf("[listaPar-ERROR]\nNão é possivel mostrar os valores pares pilha!");
	}
}

int main(){
setlocale (LC_ALL, "");
	
	int op, valor;
	int MINRangePilha = 5;
	Pilha p;
	initPilha(&p, MINRangePilha);
	
	do{
		printf("1 -  Cadastrar número\n");
		printf("2 - \ Mostrar todos números\n");
		printf("3 - Mostrar números pares\n");
		printf("4 - Excluir número\n");
		printf("5 - Sair\n");
		
		scanf("%i", &op);
		
		switch(op){
			case 1:
				printf("Digite o valor que deseja inserir: ");
				scanf("%i", &valor);
				
				push(&p, valor);
					
			break;
			case 2:
				listaFull(&p);
			break;
			case 3:
				listaPar(&p);
			break;
			case 4:
				pop(&p);				
			break;
			case 5:
				printf("Saindo...");
			break;
			default:
				printf("Opção invalida!");
			break;
		}
		
	}while(op != 5);
	
free(p.Elementos);







}

