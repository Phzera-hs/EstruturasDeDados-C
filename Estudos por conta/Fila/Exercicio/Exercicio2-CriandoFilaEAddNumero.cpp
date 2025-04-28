#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

#define MAX 5


/**/


int fila[MAX], primeiro, ultimo;


int criaFila(){
	primeiro = 0;
	ultimo = -1;
	printf("Fila iniciada com sucesso!");
	return 1;
	
}

void enqueue(int valor){
	if(ultimo < MAX-1){
		ultimo++;
		fila[ultimo] = valor;
	}else{
		printf("Não foi possivel inserir o valor!");
	}	
}

int dequeue(){
	int aux;
	if(primeiro<=ultimo){
		aux = fila[primeiro];
		fila[primeiro] = -1;
		primeiro++;
		return aux;
	}else{
		printf("Não foi possivel remover, fila sem valores");
	}
}

void Listagem(){
	printf("#### OS ELEMENTOS DA FILA SAO ###");
	int i;
	for(i=0; i<MAX;i++){
		printf("\nO valor da posição %i = %i", i+1, fila[i]);
	}
	
	printf("\n\n O cursor Primeiro é: %i", primeiro);
	printf("\n\nO cursor Ultimo é: %i\n", ultimo );
}

int main(){
setlocale (LC_ALL, "");

	int escolha, numero, x;
	bool isIniciada = 0;

	
	
	do{
		printf("[1] - Iniciar Fila\n[2] - Adicionar elemento\n[3] - Remover Elemento(O primeiro da fila)\n[4] - Listar");
	printf("\n[5] -  Sair\n\n");
	scanf("%i", &escolha);
	
		switch(escolha){
		
			case 1:
				printf("Inciando fila...\n");
				isIniciada = criaFila();
			break;
			case 2:
					if(isIniciada == 0)
						isIniciada = criaFila();
						printf("Você não iniciou a fila, estamos iniciando para você\n");
						
					if(isIniciada == 1){
						printf("Fila já iniciada!\n\n");
						break;
					}
						
				
				printf("Digite o valor que deseja inserir: ");
				scanf("%i", &numero);
				enqueue(numero);
						
				printf("\nAdicionando elemento...\n\n");
			break;
			case 3:
				x = dequeue();
					if(isIniciada == 0){
						printf("Você não iniciou a fila!Impossivel remover valor agora\nInicie a fila!");
						break;
					}
						
					
					printf("Removendo valor ...");
					
					if (x != -1){
					   printf("Valor %d removido!\n", x);
					break;
			case 4:
				if(!isIniciada)
					printf("Você não iniciou a fila!Não há o que mostrar agora\nInicie a fila!");
						break;
						
				Listagem();
			break;	
			case 5:
				printf("Saindo!");
			break;
			default:
				printf("Opção inválida!");
			break;
		}
	
	}
	}while(escolha != 5);
}
