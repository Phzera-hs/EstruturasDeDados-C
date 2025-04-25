#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int inicio, fim;
} Fila;

// Inicializa a fila
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

// Verifica se a fila está vazia
int filaVazia(Fila *f) {
    return f->inicio == f->fim;
}

// Verifica se a fila está cheia
int filaCheia(Fila *f) {
    return f->fim == MAX;
}

// Enfileira um elemento
void enfileirar(Fila *f, int valor) {
    if (!filaCheia(f)) {
        f->dados[f->fim++] = valor;
    } else {
        printf("Fila cheia!\n");
    }
}

// Imprime os elementos da fila
void imprimirFila(Fila *f) {
    for (int i = f->inicio; i < f->fim; i++) {
        printf("%d ", f->dados[i]);
    }
    printf("\n");
}

// Função para comparar duas filas
void compararFilas(Fila *f1, Fila *f2) {
    if ((f1->fim - f1->inicio) != (f2->fim - f2->inicio)) {
        if ((f1->fim - f1->inicio) > (f2->fim - f2->inicio))
            printf("Fila 1 é maior.\n");
        else
            printf("Fila 2 é maior.\n");
        return;
    }

    for (int i = 0; i < (f1->fim - f1->inicio); i++) {
        if (f1->dados[f1->inicio + i] != f2->dados[f2->inicio + i]) {
            printf("Filas têm mesmo tamanho, mas são diferentes.\n");
            return;
        }
    }
    printf("As filas são iguais.\n");
}

// Estatísticas da fila
void estatisticasFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    int maior = f->dados[f->inicio];
    int menor = f->dados[f->inicio];
    int soma = 0, count = 0;

    for (int i = f->inicio; i < f->fim; i++) {
        if (f->dados[i] > maior) maior = f->dados[i];
        if (f->dados[i] < menor) menor = f->dados[i];
        soma += f->dados[i];
        count++;
    }

    float media = (float)soma / count;
    printf("Maior: %d, Menor: %d, Média: %.2f\n", maior, menor, media);
}

// Copiar uma fila para outra
void copiarFila(Fila *origem, Fila *destino) {
    for (int i = origem->inicio; i < origem->fim; i++) {
        enfileirar(destino, origem->dados[i]);
    }
}

// Contar números ímpares
int contarImpares(Fila *f) {
    int count = 0;
    for (int i = f->inicio; i < f->fim; i++) {
        if (f->dados[i] % 2 != 0)
            count++;
    }
    return count;
}

// Contar números pares
int contarPares(Fila *f) {
    int count = 0;
    for (int i = f->inicio; i < f->fim; i++) {
        if (f->dados[i] % 2 == 0)
            count++;
    }
    return count;
}

// Função principal
int main() {

    	setlocale(LC_ALL, "");
		
    Fila f1, f2, f3;
    inicializarFila(&f1);
    inicializarFila(&f2);
    inicializarFila(&f3);

    // Adicionando elementos nas filas
    enfileirar(&f1, 1);
    enfileirar(&f1, 2);
    enfileirar(&f1, 3);
    enfileirar(&f1, 4);
    enfileirar(&f1, 5);

    enfileirar(&f2, 1);
    enfileirar(&f2, 2);
    enfileirar(&f2, 3);
    enfileirar(&f2, 4);
    enfileirar(&f2, 5);

    // Comparar filas
    compararFilas(&f1, &f2);

    // Estatísticas
    estatisticasFila(&f1);

    // Copiar f1 para f3
    copiarFila(&f1, &f3);
    printf("Fila copiada (f3): ");
    imprimirFila(&f3);

    // Contar pares e ímpares
    printf("Quantidade de ímpares em f1: %d\n", contarImpares(&f1));
    printf("Quantidade de pares em f1: %d\n", contarPares(&f1));

    return 0;
}

