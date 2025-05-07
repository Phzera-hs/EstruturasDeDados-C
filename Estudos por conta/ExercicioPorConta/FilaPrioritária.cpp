#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>

typedef struct {
    int idade;
    char nome[50];
} Pessoa;

typedef struct {
    int inicio;
    int final;
    int quantidade;
    Pessoa *dados;
} Fila;

void initFila(Fila *fi, int qntd) {
    fi->dados = (Pessoa *)malloc(qntd * sizeof(Pessoa));
    fi->inicio = 0;
    fi->final = -1;
    fi->quantidade = qntd;
}

void liberaFila(Fila *fi) {
    free(fi->dados); // Corrigido
}

void enqueue(Fila *fi, Pessoa pessoa) {
    if (fi->final < fi->quantidade - 1) {
        fi->final++;
        fi->dados[fi->final] = pessoa;
    } else {
        printf("Não é possível inserir os dados: fila cheia.\n");
    }
}

void dequeue(Fila *fi){
	Pessoa aux;
	if(fi->final >= 0){
		aux = fi->dados[fi->inicio];
		printf("Pessoa removida:\nNome%s\nIdade %i!", aux.nome, aux.idade);
		fi->inicio++;
	}else{
	printf("Fila vazia!");
	}
}

void printFila(Fila *fi) {
    if (fi->final == -1) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Conteúdo da fila:\n");
    for (int i = fi->inicio; i <= fi->final; i++) {
        printf("Nome: %s | Idade: %d\n", fi->dados[i].nome, fi->dados[i].idade);
    }
}

void alocaFilaPrioritaria(Fila *prioritaria, Fila *padrao){
	for(int i = 0; i <= padrao->final; i++){
		if(padrao->dados[i].idade >= 60){
			enqueue(prioritaria, padrao->dados[i]);
		}
	}
}

int main() {
    setlocale(LC_ALL, "");

    Pessoa pessoa;
    Fila fiPadrao, fiPriorit;

    initFila(&fiPadrao, 2);
		initFila(&fiPriorit, 2);    

    printf("Digite o nome da pessoa: ");
    fflush(stdin);
    gets(pessoa.nome);
    fflush(stdin);

    printf("Digite a idade da pessoa: ");
    scanf("%d", &pessoa.idade);

    enqueue(&fiPadrao, pessoa);
    
    printf("Digite o nome da pessoa: ");
    fflush(stdin);
    gets(pessoa.nome);
    fflush(stdin);

    printf("Digite a idade da pessoa: ");
    scanf("%d", &pessoa.idade);

    enqueue(&fiPadrao, pessoa);
    
//    dequeue(&fiPadrao);
		alocaFilaPrioritaria(&fiPriorit, &fiPadrao);

    printFila(&fiPadrao);
    
    printFila(&fiPriorit);

    liberaFila(&fiPadrao);

    return 0;
}

