#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct{
	int matricula;
	float nota1,nota2, media;
	char nome[10];
	
}Aluno;

typedef struct{
	int topo;
	int quantidade;
	Aluno *aluno;

}Pilha;


void initPilha(Pilha *pi, int quantidade){
	
	pi->topo = -1;
	pi->aluno = (Aluno *)malloc(quantidade * sizeof(Aluno));
	pi->quantidade = quantidade;

}

bool isEmpty(Pilha *pi){
	return pi->topo < 0;
}

bool isFull(Pilha *pi){
	return pi->topo == pi->quantidade - 1;
}

void push(Pilha *pi, Aluno dado){
	if(!isFull(pi)){
		pi->topo++;
		pi->aluno[pi->topo] = dado;
		printf("Aluno inserido!\n\n");
	}else{
		printf("Aluno não inserido!\n\n");
	}
}

void pop(Pilha *pi){
	Aluno aux;
	if(!isEmpty(pi)){
		aux = pi->aluno[pi->topo];
		printf("Aluno %s removido com sucesso\n\n", aux.nome);
		pi->topo--;
	}else{
		printf("Aluno não removido\n\n");
	}
}

void peek(Pilha *p){
	if(!isEmpty(p))
		printf("Aluno:%s\nN1:%.2f\nN2:%.2f\nMedia:%.2f\n\n", p->aluno[p->topo].nome, p->aluno[p->topo].nota1, p->aluno[p->topo].nota2, p->aluno[p->topo].media);
}

void listaAll(Pilha *p){
	if(!isEmpty(p))
		for(int i = p->topo; i >= 0; i--){
			printf("Aluno:%s\nN1:%.2f\nN2:%.2f\nMedia:%.2f\n\n", p->aluno[i].nome, p->aluno[i].nota1, p->aluno[i].nota2, p->aluno[i].media);
	
		}
}


int main(){
	Pilha pi;
	Aluno aluno;
	int quantidade, opcao;
	printf("Qual o tamanho minimo dessa pilha: ");
	scanf("%i", &quantidade);
	float soma;
	
	initPilha(&pi, quantidade);
	
	do{
		printf("[1] - Inserir aluno\n");
		printf("[2] - Remover aluno\n");
		printf("[3] - Mostrar aluno do topo\n");
		printf("[4] - Mostrar todos\n");
		printf("[5] - Encerrar!\n");
		printf("Digite:");
		scanf("%i", &opcao);
		printf("\n");
		
		switch(opcao){
			case 1:
				printf("Digite o nome: ");
				fflush(stdin);
				gets(aluno.nome);
				fflush(stdin);
				printf("Digite a nota 1: ");
				scanf("%f", &aluno.nota1);
				printf("Digite a nota 2: ");
				scanf("%f", &aluno.nota2);
			 	soma = (aluno.nota1 + aluno.nota2)/2;
				aluno.media = soma;
				push(&pi, aluno);
							
			break;
			case 2:
				pop(&pi);
			break;
			case 3:
				peek(&pi);			
			break;
			case 4:
				listaAll(&pi);			
			break;
			case 5:
				printf("Encerrando!\n");
			break;
			default:
				printf("Opção inválida!\n");
			break;
			
		}
	
	}while(opcao != 5);
	



}
