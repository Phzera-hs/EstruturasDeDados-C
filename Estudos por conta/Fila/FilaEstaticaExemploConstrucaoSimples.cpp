#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>


#define MAX 3

/**/
int primeiro=0;
int ultimo=-1;
int Fila[MAX];

void enqueue(int valor){
	if(ultimo < MAX-1){
		ultimo++;
		Fila[ultimo] = valor;
		printf("Valor inserido com sucesso!");
	}
	else{
		printf("N�o foi possivel inserir o valor!");
	}
}

int dequeue(){
	int aux;
	if(primeiro<=ultimo){
		aux = Fila[primeiro];
		Fila[primeiro]= -1;
		primeiro++;
		return aux;
	}
	else{
		printf("A fila se encontra vazia");
	}
}

void Listagem(){
	printf("#### OS ELEMENTOS DA FILA SAO ###");
	int i;
	for(i=0; i<MAX;i++){
		printf("\nO valor da posi��o %i = %i", i+1, Fila[i]);
	}
	
	printf("\n\n O cursor Primeiro �: %i", primeiro);
	printf("\n\nO cursor Ultimo �: %i\n", ultimo );
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
	
	for(i = 0; i < MAX;i++){
		Fila[i] = 0;
	}
}


int main(){
setlocale(LC_ALL, ""); // Configura��o para suportar caracteres especiais

    char op;
    int novo;

    // Loop de intera��o at� o usu�rio escolher "E" para encerrar
    do {
        // Exibe o menu de op��es
        printf("\nI - Inserir um elemento na Fila\n");
        printf("R - Remover um elemento da Fila\n");
        printf("L - Listar os elementos da Fila\n");
        printf("V - Visualizar o primeiro elemento na Fila\n");
        printf("T - Tamanho da Fila\n");
        printf("D - Deletar(Limpar) todos os elementos da Fila\n");
        printf("E - Encerrar o programa\n");

        fflush(stdin); // Limpa o buffer de entrada
        scanf("%c", &op); // L� a op��o do usu�rio

        // Switch para executar a op��o escolhida
        switch(op){
            case 'I':
            case 'i':
                printf("Digite um valor para inserir na fila: ");
                scanf("%d", &novo);
                enqueue(novo);
                break;
            
            case 'R':
            case 'r':
                novo = dequeue();
                if(novo != -1) {
                    printf("Valor removido da fila: %d\n", novo);
                }
                break;
            
            case 'L':
            case 'l':
                Listagem();
                break;
            
            case 'V':
            case 'v':
                novo = peek();
                if(novo != -1) {
                    printf("Primeiro elemento da fila: %d\n", novo);
                } else {
                    printf("Fila vazia!\n");
                }
                break;
            
            case 'T':
            case 't':
                printf("Tamanho da fila: %d\n", size());
                break;
            
            case 'D':
            case 'd':
                clear();
                break;
            
            case 'E':
            case 'e':
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Op��o inv�lida! Tente novamente.\n");
        }
    } while(op != 'E' && op != 'e'); // Continua at� o usu�rio escolher 'E' para encerrar

    return 0;



}

