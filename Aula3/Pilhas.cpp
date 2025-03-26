#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tamanho 10

int topo=0;

int pilha[tamanho];

int Size_pilha(){
	return topo;
}

void Push(int valor){
	if(topo<tamanho){
		pilha[topo]=valor; //pilha na posição topo recebe o valor digitado
		topo++;
		printf("Inserção realizada com sucesso!\n\n\n");
	}
	
	else{
		printf("ERRO: A pilha já está cheia.\n");
		
	}
}

int pop(){
	
	if(topo==0){
		printf("ERRO: A pilha encontra-se vazia.\n");
		return 0;
		
	}else{
		topo--;
		return pilha[topo];
	}
}

void Lista_Pilha(){
	int i;
	printf("\n\nO valor da pilha sao: ");
	for(i=0;i<topo;i++){
		printf("O valor na posicao %i é %i\n", i+1, pilha[i]);
	}
}

int main(){
	
	setlocale(LC_ALL, "");
	
	char op;
	int aux;
	
	printf("\n ----------- Bem Vindo ao nosso Sistema de Pilhas -----------\n");
	
	while(op!='S' || op!='s'){
		printf("A - Adicionar um Elemento da Pilha.\n");
		printf("R - Remover um Elemento da Pilha.\n");
		printf("T - Tamanho atual da Pilha.\n");
		printf("L - Para listar os Elemento da Pilha.\n");
		printf("U - Para listar último Elemento da Pilha.\n");
		printf("S - Para sair.\n");
		
		fflush(stdin); //LER CARACTER - SEM LIXO DE MEMORIA
		scanf("%c", &op);
		
		if(op=='A'|| op=='a'){
		printf("\n Informe o valor que deseja inserir: ");
		scanf("%i", &aux);
		Push(aux);
		}
		
		else if (op == 'R' || op == 'r') {
         int valor_removido = pop(); // Captura o valor removido
         if (valor_removido != 0) {
             printf("\nO valor %i foi Removido com sucesso!\n", valor_removido);
         }
		
	}
		else if(op=='L' || op == 'l'){
			Lista_Pilha();
		}

	}	
	
	return 0;
}
