#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>

typedef struct{
	
	char nome[20];
	int grau;
	
}Doencas;

typedef struct{

	char nome[30];
	int idade;
	Doencas doente;	
	
}Pessoas;

typedef struct{
	
	int comeco;
	int final;
	Pessoas *dados;
	int quantidade;

}Fila;

typedef struct{
	
	int topo;
	Doencas *doencas;
	
}Pilha;

void IniciaFila(Fila *fi, int quantidade){
	fi->comeco = 0;
	fi->final = -1;
	fi->dados = (Pessoas *)malloc(quantidade * sizeof(Pessoas));
	fi->quantidade = quantidade;
}

bool isEmptyFila(Fila *fi){
	return fi->final < fi->comeco;
}

bool isFullFila(Fila *fi){
	return fi->final == fi->quantidade-1;
}

void IniciaPilha(Pilha *pi){
	pi->topo = -1;
	pi->doencas = (Doencas*)malloc(5 * sizeof(Doencas));
}

bool isEmptyPilha(Pilha *pi){
	return pi->topo == -1;
}

bool isFullPilha(Pilha *pi){
	return pi->topo == 5-1;
}

void enqueue(Fila *fi, Pessoas pessoa){
	if(!isFullFila(fi)){
		fi->final++;
		fi->dados[fi->final] = pessoa;
		printf("Paciente %s cadastrada!\n", pessoa.nome);
	}else{
		printf("[ERRO: enqueue] Fila cheia!\n");
	}
}

void dequeue(Fila *fi){
	if(!isEmptyFila(fi)){
		fi->comeco++;
	}else{
		printf("[ERRO: dequeue] Fila vazia!\n");
	}
}

void push(Pilha *pi, Doencas doenca){
	if(!isFullPilha(pi)){
		pi->topo++;
		pi->doencas[pi->topo] = doenca;
	}
}

//pop

void listarAll(Pilha *pi, Fila *fi){
	if(!isEmptyFila(fi) && !isEmptyPilha(pi)){
		
		printf("PACIENTES CADASTRADOS!\n");
		for(int i = fi->comeco; i <= fi->final; i++){
			printf("Nome:%s\n", fi->dados[i].nome);
			printf("Idade:%i\n", fi->dados[i].idade);
			printf("Doenca: %s\n\n", fi->dados[i].doente.nome);
		}
		
		printf("DOENÇAS E SEUS GRAUS!\n");
		for(int i = pi->topo; i >= 0; i--){
			printf("Nome da doença: %s | %i\n\n", pi->doencas[i].nome, pi->doencas[i].grau);
		}
	}
}

int main(){

	setlocale(LC_ALL, "");

	Pilha pi;
	IniciaPilha(&pi);
	Doencas doencas[5];
		for(int i = 0; i < 5;i++){
			printf("Digite o nome da doença: ");
			fflush(stdin);
			gets(doencas[i].nome);
			
			printf("Digite o grau da doença: ");
			fflush(stdin);
			scanf("%i", &doencas[i].grau);
			push(&pi, doencas[i]);
		}
		
	int opcao;
Fila fi;
int qtdFila;

printf("\nDigite a quantidade de pacientes para a fila: ");
scanf("%d", &qtdFila);
IniciaFila(&fi, qtdFila);


do {
    printf("\n===== MENU =====\n");
    printf("1 - Cadastrar paciente na fila\n");
    printf("2 - Remover paciente da fila\n");
    printf("3 - Listar todos os pacientes e doenças\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    fflush(stdin);

    switch(opcao) {
        case 1: {
            Pessoas pessoa;
            printf("Nome do paciente: ");
            gets(pessoa.nome);
            printf("Idade do paciente: ");
            scanf("%d", &pessoa.idade);
            fflush(stdin);
            printf("Nome da doença do paciente: ");
            gets(pessoa.doente.nome);
            printf("Grau da doença (0 a 4): ");
            int grauIndex;
            scanf("%d", &grauIndex);
            pessoa.doente.grau = grauIndex; // você pode ajustar se quiser usar mais graus
            enqueue(&fi, pessoa);
            break;
        }
        case 2:
            dequeue(&fi);
            break;
        case 3:
            listarAll(&pi, &fi);
            break;
        case 0:
            printf("Encerrando programa...\n");
            break;
        default:
            printf("Opção inválida!\n");
    }

} while(opcao != 0);
	
}


