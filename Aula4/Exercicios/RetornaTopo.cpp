/*Faça uma função que receba uma pilha como argumento e retorne o valor
armazenado em seu topo. A função deve remover também esse elemento.*/

#include <stdio.h>
#include <stdlib.h> // para alocação dinâmica
#include <string.h>


//SAO OBRIGATORIAS
typedef struct Elemento{
	int *dado;
	struct Elemento *seguinte;
}Elemento;

typedef struct Pilha {
    Elemento *inicio;
    int tamanho;
} Pilha;


void Init_Pilha(Pilha *pilha) {
    pilha->inicio = NULL;
}
//SAO OBRIGATORIAS


int Push_pilha(Pilha *pilha, const int *number ){
	Elemento *novoElemento;
	
		//ALOCANDO MEMORIA
		
			//FALHA PARA O NOVO ELEMENTO
	if((*novoElemento = (Elemento *)malloc(sizeof(Elemento))) == NULL)
		return -1;
		
			//FALHA NO DADO 
	if ((novoElemento->dado = (int *)malloc(10 * sizeof(int))) == NULL)
        free(novoElemento);
        return -1;
    
    	//ALOCANDO MEMORIA
    	
    	
	strcpy(novoElemento->dado, texto);
	novoElemento->seguinte = pilha->inicio;
    pilha->inicio = novoElemento;
    pilha->tamanho++;
}

int void main(){
	
	
	
	
	
}
