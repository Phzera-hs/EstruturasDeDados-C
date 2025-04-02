#include <stdio.h>
#include <stdlib.h>//para alocação dinâmica
#include <string.h>

//Inicialmente criamos o elemento dentro da nossa pilha,
typedef struct //ElementoPrimitivo
{
	char *dado;//dado que quero colocar dentro da pilha.
	struct ElementoPrimitivo *seguinte;//armazeno o dado e a próx posição da pilha.
}Elemento;

//Pilha propriamente dita
typedef struct //ListaPilha
{
	Elemento *inicio;//ponteiro p/inicio da pilha podem chamar de topo se quiserem.
	int tamanho; //tamanho da pilha
}Pilha;

//vou inicializar a pilha
void Init_Pilha(Pilha *pilha)//Pilha (Maiuscula tipo) pilha (minuscula variável).
{
	pilha->inicio = NULL;
	pilha->tamanho=0;
}

int Push_Pilha(Pilha *pilha, char *texto)
{
	Elemento *novo_elemento;
	if((novo_elemento = (Elemento*)malloc(sizeof(Elemento)))==NULL)//alocação e verificação se deu certa alocação
		return -1;//se eu não entrar a alocação deu certo
	if ((novo_elemento->dado = (char*)malloc(10*sizeof(char)))==NULL)//alocando para o dado q vou inserir no elemento
		return -1;
	strcpy(novo_elemento->dado, texto);
	novo_elemento->seguinte = pilha->inicio;//mudo o ponteiro para o inicio
	pilha->inicio = novo_elemento;
	pilha->tamanho++; //trabalhando com o  topo
	return 0;
}


	
int Pop_Pilha(Pilha *pilha)
{
	Elemento *remove_elemento;
	if(pilha->tamanho==0)
		return -1;
	remove_elemento = pilha->inicio; //copiando para um auxiliar
	pilha->inicio = pilha->inicio->seguinte;
	free(remove_elemento->dado);//fiz a copia para poder desalocar
	free(remove_elemento);//primeiro desaloco o dado (modifico os ponteiros), depois a estrutua
	pilha->tamanho--;     // de dentro pra fora.
	return 0;
}


void List_Pilha(Pilha *pilha)
{ 
	Elemento *atual;
	int i;
	atual = pilha->inicio;
	
	printf("------- TOPO DA PILHA ----------\n");
	
	for(i=0; i<pilha->tamanho; i++)
	{
		printf("  %s\n", atual->dado);
		atual = atual->seguinte;
	}
	
	printf("------- FUNDO DA PILHA ----------\n");

}

	
int main()
{
	Pilha *teste1;
	char aux[11];
	int i;
	
	if((teste1 = (Pilha*)malloc(sizeof(Pilha)))==NULL)
		return -1;
	Init_Pilha(teste1);
	
	for(i=0; i<3; i++)
	{
		printf("Digite alguma coisa com ate 10 caracteres: ");
		scanf("%s", &aux);
		Push_Pilha(teste1, aux);
		printf("A pilha tem %i elementos. \n", teste1->tamanho);
		List_Pilha(teste1);
	}
	Pop_Pilha(teste1);
	printf("Agora a pilha tem %i elementos.", teste1->tamanho);
	List_Pilha(teste1);
	
}

