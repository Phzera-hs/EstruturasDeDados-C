#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int elementos[MAX];
    int inicio;
    int final;
} Fila;

void InitFila(Fila *fi) {
    fi->inicio = 0;
    fi->final = -1;
}

bool isEmpty(Fila *fi) {
    return fi->inicio > fi->final;
}

bool isFull(Fila *fi) {
    return fi->final == MAX - 1;
}

void enqueue(Fila *fi, int valor) {
    if (!isFull(fi)) {
        fi->final++;
        fi->elementos[fi->final] = valor;
        printf("Valor %d inserido na fila!\n", valor);
    } else {
        printf("Fila cheia!\n");
    }
}

int dequeue(Fila *fi) {
    if (!isEmpty(fi)) {
        int valor = fi->elementos[fi->inicio];
        fi->inicio++;
        printf("Valor %d removido da fila.\n", valor);
        return valor;
    } else {
        printf("Fila vazia!\n");
        return -1;
    }
}

void Listagem(Fila *fi) {
    printf("Fila: ");
    if (!isEmpty(fi)) {
        for (int i = fi->inicio; i <= fi->final; i++) {
            printf("[%d] ", fi->elementos[i]);
        }
        printf("\n");
    } else {
        printf("Fila vazia.\n");
    }
}

int contarPares(Fila *fi) {
    int cont = 0;
    for (int i = fi->inicio; i <= fi->final; i++) {
        if (fi->elementos[i] % 2 == 0)
            cont++;
    }
    return cont;
}

int contarImpares(Fila *fi) {
    int cont = 0;
    for (int i = fi->inicio; i <= fi->final; i++) {
        if (fi->elementos[i] % 2 != 0)
            cont++;
    }
    return cont;
}

void menorMaior(Fila *fi, int *menor, int *maior) {
    if (isEmpty(fi)) return;

    *menor = fi->elementos[fi->inicio];
    *maior = fi->elementos[fi->inicio];

    for (int i = fi->inicio + 1; i <= fi->final; i++) {
        if (fi->elementos[i] < *menor)
            *menor = fi->elementos[i];
        if (fi->elementos[i] > *maior)
            *maior = fi->elementos[i];
    }
}

float media(Fila *fi) {
    if (isEmpty(fi)) return 0;

    int soma = 0;
    int count = 0;
    for (int i = fi->inicio; i <= fi->final; i++) {
        soma += fi->elementos[i];
        count++;
    }
    return (float)soma / count;
}

bool filasIguais(Fila *f1, Fila *f2) {
    if ((f1->final - f1->inicio) != (f2->final - f2->inicio)) return false;

    for (int i = 0; i <= f1->final - f1->inicio; i++) {
        if (f1->elementos[f1->inicio + i] != f2->elementos[f2->inicio + i])
            return false;
    }
    return true;
}

void copiarFila(Fila *origem, Fila *destino) {
    InitFila(destino);
    for (int i = origem->inicio; i <= origem->final; i++) {
        enqueue(destino, origem->elementos[i]);
    }
    printf("Fila copiada com sucesso!\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Fila fila1, fila2;
    InitFila(&fila1);
    InitFila(&fila2);

    int opcao, valor;

    do {
        printf("\n======= MENU FILA =======\n");
        printf("1 - Inserir na fila 1\n");
        printf("2 - Inserir na fila 2\n");
        printf("3 - Remover da fila 1\n");
        printf("4 - Listar fila 1 e 2\n");
        printf("5 - Verificar se filas são iguais\n");
        printf("6 - Copiar fila 1 para fila 2\n");
        printf("7 - Contar pares e ímpares da fila 1\n");
        printf("8 - Maior, menor e média da fila 1\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Valor para fila 1: ");
                scanf("%d", &valor);
                enqueue(&fila1, valor);
                break;
            case 2:
                printf("Valor para fila 2: ");
                scanf("%d", &valor);
                enqueue(&fila2, valor);
                break;
            case 3:
                dequeue(&fila1);
                break;
            case 4:
                printf("Fila 1:\n");
                Listagem(&fila1);
                printf("Fila 2:\n");
                Listagem(&fila2);
                break;
            case 5:
                if (filasIguais(&fila1, &fila2))
                    printf("As filas são iguais.\n");
                else
                    printf("As filas são diferentes.\n");
                break;
            case 6:
                copiarFila(&fila1, &fila2);
                break;
            case 7:
                printf("Pares: %d | Ímpares: %d\n", contarPares(&fila1), contarImpares(&fila1));
                break;
            case 8: {
                int menor, maior;
                menorMaior(&fila1, &menor, &maior);
                printf("Menor: %d | Maior: %d | Média: %.2f\n", menor, maior, media(&fila1));
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}

