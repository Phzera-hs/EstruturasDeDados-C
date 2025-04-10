//Implementar uma FILA de 5 posições de inteiros.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 5

//Se primeiro>ultimo não tenho nada dentro da fila 
int primeiro=0;
int ultimo=-1;
int Fila[tam];

void enqueue(int valor){
	
	if(ultimo<tam-1){ //Ultima vez que ele entra no if é p/ tam=3
	
		ultimo++;
		Fila[ultimo]= valor;
		printf("\nValor inserido com Sucesso\n");

	}else{
		printf("\nNão foi possivel inserir o elemento na Fila\n");
	}
}

int dequeue(){
	int aux;
	if(primeiro<=ultimo){	
		aux=Fila[primeiro];
		Fila[primeiro]=-1;
		primeiro++;
		return aux;
	}
	else
	{
		printf("\n A fila encontra-se vazia!!\n\n");
	}
}

void List(){
	int i;
	printf("\n ####### OS ELEMENTOS DA LISTA SAO ######## \n");
	
	for(i=0; i<tam;i++){
		printf("\nO valor da posição %i = %i", i+1, Fila[i]);
	}
	
	printf("\n\n O cursor Primeiro é: %i", primeiro);
	printf("\n\nO cursor Ultimo é: %i\n", ultimo );
}

int peek(){
	if(primeiro <= ultimo){
		return Fila[primeiro];
	}
	else{
		return -1;
	}
}

int size(){
	
	return(ultimo - primeiro+1);
}

void clear(){
	int i;
	primeiro = 0;
	ultimo =-1;
	
	for(i = 0; i < tam;i++){
		Fila[i] = 0;
	}
}

int main(){
	setlocale(LC_ALL, "");
	
	char op;
	int novo;
	
	while(op != 'E' && op != 'e'){
		printf(" I - Inserir um elemento na Fila\n");
		printf(" R - Remover um elemento na Fila\n");
		printf(" L - Listar os elementos da Fila\n");
		printf(" V - Visualizar o primeiro elemento na Fila\n");
		printf(" T - Tamanho da Fila\n");
		printf(" D - Deletar(Limpar) elementos da Fila\n");
		printf(" E - Encerrar o programa\n");
		fflush(stdin);
		scanf("%c", &op);
	}
	
	return 0;
}
