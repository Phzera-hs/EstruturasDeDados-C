#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>


/**/	

typedef struct{ //Estrutura dos dados
	
	int matricula;
	char nome[30];
	float n1,n2,n3;

}Aluno;

typedef struct{ //Define as posiçoes dos dados

	Elemento *inicio;
	Elemento *final;

}Fila;

typedef struct{ //Guarda a referencia do proximo dado/elemento
	
	Aluno dados;
	Elemento *proximo; 
	
}Elemento;


Fila* cria_Fila(){
	Fila* fi = (Fila*) malloc(sizeof(Fila);
	if(fi != NULL){
		fi->final = NULL;
		fi->inicio = NULL;
	}
	return fi; 
}

void libera_Fila(Fila *fi){
	if(fi != NULL){
		Elemento* no;
		while(fi->inicio != NULL){
			no = fi->inicio;
			fi->inicio = fi->inicio->proximo;
			free(no);
		}
		free(fi);
	}
}

int tamanho_Fila(Fila* fi){
	if(fi == NULL){
		return 0;
	}
	
	int cont = 0;
	
	Elemento* no = fi->inicio;
	while(no != NULL){
		cont++;
		no = no->proximo;
	}
	return cont;
}

int Fila_cheia(Fila* fi){
	return 0;
}

int Fila_vazia(Fila* fi){ //boolean
	if(fi == NULL){
		return 1;
	}
	if(fi->inicio == NULL){
		return 1;	
	}
	return 0;	
}

int insere_Fila(Fila* fi, Aluno aluno){
	if(fi == NULL){
		return 0;
	}
	
	Elemento *no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL){
		return 0;
	}
	
	no->dados = aluno;
	no->proximo = NULL;
	if(fi->final == NULL){
		fi->inicio = no;
	}
	else{
		fi->final->prox = no;
	}
	fi->final = no;
	
	return 1;
	
}

int remove_Fila(Fila* fi){
	if(fi == NULL){
		return 0;
	}
	
	if(fi->inicio == NULL){
		return 0;
	}
	Elemento *no = fi->inicio;
	fi->inicio = fi->inicio->proximo;
	if(fi->inicio == NULL){
		fi->final = NULL;
	}
	free(no);
	
	return 1;
	
}

int consulta_Fila(Fila* fi, Aluno aluno){
	if(fi == NULL){
		return 0;
	}
	if(fi->inicio == NULL){
		return 0;
	}
	
	*aluno = fi->inicio->dados;
	return 1;
}

int main(){
setlocale (LC_ALL, "");

	Fila *fi;
	int x, int isTrueORFalse; //Retorno 1 = Deu certo | Retorno 0 = Deu Errado;
	
	fi = cria_Fila();
	
	x = tamanho_Fila(fi);
	isTrueORFalse = Fila_cheia(fi);  //boolean int
	isTrueORFalse = Fila_vazia(fi);	//boolean int
	isTrueORFalse = insere_Fila(fi, dados_aluno); //boolean int
	isTrueORFalse = remove_Fila(fi);//boolean int
	isTrueORFalse = consulta_Fila(fi, &dados_aluno); //boolean int e 
																	//&dados_aluno na posicao
																	//de memoria do aluno consultado






}

