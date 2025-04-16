#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

#define MAX 10
typedef struct {
    int itens[MAX];
    int topo;
} Pilha;


void init(Pilha *p) {
    p->topo = -1;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}


int cheia(Pilha *p) {
    return p->topo == MAX - 1;
}


void push(Pilha *p, int valor) {
    if (!cheia(p)) {
        p->itens[++p->topo] = valor;
    } else {
        printf("Pilha cheia!\n");
    }
}

void comparaPilhas(Pilha *p1, Pilha *p2) {
    if (p1->topo != p2->topo) {

        printf("As pilhas s�o diferentes.\n");
        if (p1->topo > p2->topo)
            printf("P1 � maior (mais elementos).\n");
        else
            printf("P2 � maior (mais elementos).\n");
        return;
    }

    for (int i = 0; i <= p1->topo; i++) {
        if (p1->itens[i] != p2->itens[i]) {
            printf("As pilhas s�o diferentes.\n");
            for (int j = 0; j <= p1->topo; j++) {
                if (p1->itens[j] > p2->itens[j]) {
                    printf("P1 � maior (elemento maior na posi��o %d).\n", j);
                    return;
                } else if (p1->itens[j] < p2->itens[j]) {
                    printf("P2 � maior (elemento maior na posi��o %d).\n", j);
                    return;
                }
            }
        }
    }

    printf("As pilhas s�o iguais.\n");
}


float mediaAritmetica(Pilha *p){
    int i = 0;
    int ciclosDaPilha = 0;
    int soma = 0;
    
    for(i = 0; i <= p->topo; i++){ // A compara��o aqui deve ser <= topo, n�o < MAX
        soma += p->itens[i];
        ciclosDaPilha++;
        printf("\nVALOR = [%i]", p->itens[i]);
        printf(" | CICLOS = [%i]\n\n", ciclosDaPilha);
    }
    
    if (ciclosDaPilha == 0) {
        return 0; // Evita divis�o por zero
    }
    
    return (float) soma / ciclosDaPilha; // Cast para garantir precis�o
}

void clonaPilha(Pilha *p1, Pilha *p2){
	int aux;
	if(p1->topo == p2->topo)
		for(int i = 0; i < p1->topo; i++){
			aux = p1->itens[i];
			p1->itens[i] = p2->itens[i];
			p2->itens[i] = aux;
		}
	else{
		printf("As pilhas n�o possuem o mesmo tamanho");

	}
}

void contaImpar(Pilha *p){
	int ContaImpar = 0;
	for(int i = 0; i <= p->topo; i++)
		if(p->itens[i] % 2 != 0){
			ContaImpar++;
		}
		printf("H� %i numeros impares na Pilha\n", ContaImpar);
	
	
}

void contaPar(Pilha *p){
	int ContaPar = 0;
	for(int i = 0; i <= p->topo; i++)
		if(p->itens[i] % 2 == 0){
			ContaPar++;
		}
	printf("H� %i numeros pares na Pilha\n", ContaPar);	
	
}


int main(void) {
	
	setlocale(LC_ALL, "");
	
    Pilha P1, P2;
    float MediaAritmeticaP1, MediaAritmeticaP2;
    init(&P1);
    init(&P2);
    
    push(&P1, 20);
    push(&P1, 21);
    push(&P1, 5);

    push(&P2, 40);
    push(&P2, 2);
    push(&P2, 3);
    
    MediaAritmeticaP1 = mediaAritmetica(&P1);
    MediaAritmeticaP2 = mediaAritmetica(&P2);
    
    printf("A media aritmetica da p1 = %.2f\n", MediaAritmeticaP1);
    contaPar(&P1);
    contaImpar(&P1);
    printf("A media aritmetica da p2 = %.2f\n", MediaAritmeticaP2);
	contaPar(&P2);
    contaImpar(&P2);

    comparaPilhas(&P1, &P2);
	clonaPilha(&P1, &P2);
	comparaPilhas(&P1, &P2);
	
	
	return 0;
}

