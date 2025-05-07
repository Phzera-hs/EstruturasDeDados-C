#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int *elemento;
    int topo;
    int tamanho;
} Pilha;

void initPilha(Pilha *p, int tamanho) {
    p->elemento = (int *)malloc(tamanho * sizeof(int));
    p->topo = -1;
    p->tamanho = tamanho;
}

void push(Pilha *p, int valor) {
    if(p->topo < p->tamanho - 1){
        p->topo++;
        p->elemento[p->topo] = valor;
    } else {
        printf("Não foi possível inserir o valor! Pilha cheia.\n");
    }
}

void pop(Pilha *p) {
    if(p->topo >= 0){
        int aux = p->elemento[p->topo];
        p->topo--;
        printf("Valor %i removido!\n", aux);
    } else {
        printf("Não foi possível remover o valor! Pilha vazia.\n");
    }
}

void lista(Pilha *p) {
    if(p->topo >= 0){
        printf("PILHA DE FIBONACCI:\n");
        for(int i = 0; i <= p->topo; i++){
            printf("[%i]\n", p->elemento[i]);
        }
        printf("Topo = %i\n", p->topo);
    } else {
        printf("Pilha vazia!\n");
    }
}

void liberarPilha(Pilha *p) {
    free(p->elemento);
}

int main() {
    setlocale(LC_ALL, "");

    int n, t1 = 0, t2 = 1, aux;

    printf("Quantos valores deseja armazenar? ");
    scanf("%i", &n);

    Pilha p;
    initPilha(&p, n);

    for(int i = 0; i < n; i++) {
        push(&p, t1);
        aux = t1 + t2;
        t1 = t2;
        t2 = aux;
    }

    lista(&p);
    liberarPilha(&p);

    return 0;
}

