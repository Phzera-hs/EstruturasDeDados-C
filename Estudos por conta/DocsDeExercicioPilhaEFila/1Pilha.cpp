#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

#define MAX 5

typedef struct {
    int elementos[MAX];
    int topo;
} Pilha;

void initPilha(Pilha *p) {
    p->topo = -1;
}

bool isEmpty(Pilha *p) {
    return p->topo == -1;
}

bool isFull(Pilha *p) {
    return p->topo == MAX - 1;
}

int Tamanho(Pilha *p) {
    // [CORREÇÃO] Você fez:
    // return p->topo; ? isso retornaria um a menos que o total real de elementos.
    // Correção: soma 1 ao índice do topo.
    return p->topo + 1;
}

void Push(Pilha *p, int valor) {
    if (isFull(p)) {
        printf("Pilha cheia!\n"); // [CORREÇÃO] Adicionado \n para melhor formatação.
        return; // [CORREÇÃO] Você esqueceu de sair da função após a mensagem.
    }

    p->topo++;
    p->elementos[p->topo] = valor;
    printf("Valor inserido: %d\n", valor); // [CORREÇÃO] Adicionado \n.
}

int pop(Pilha *p) {
    if (isEmpty(p)) {
        printf("Pilha vazia!\n"); // [CORREÇÃO] Adicionado \n.
        return -1; // [CORREÇÃO] Adicionado retorno para indicar erro.
    }

    int aux = p->elementos[p->topo];
    p->topo--;
    printf("Valor %d removido!\n", aux); // [CORREÇÃO] Adicionado \n.
    return aux;
}

int topo(Pilha *p) {
    if (isEmpty(p)) {
        printf("Pilha vazia!\n"); // [CORREÇÃO] Adicionado \n.
        return -1; // [CORREÇÃO] Adicionado retorno para evitar valor indefinido.
    }
    return p->elementos[p->topo];
}

void listar(Pilha *p) {
    if (isEmpty(p)) {
        printf("Pilha vazia!\n");
    } else {
        printf("Pilha: ");
        // [CORREÇÃO] Você usou: for (int i = 0; i < p->topo; i++)
        // Isso exibe um a menos que o correto.
        // Correto é: i <= p->topo;
        for (int i = 0; i <= p->topo; i++) {
            printf("[%d] ", p->elementos[i]);
        }
        printf("\n");
    }
}

bool Identicas(Pilha *p1, Pilha *p2) {
    if (Tamanho(p1) != Tamanho(p2)) {
        return false;
    }

    for (int i = 0; i <= p1->topo; i++) {
        // [CORREÇÃO] Você tinha feito:
        // if (p1->elementos[i] != p1->elementos[i])
        // Isso compara o mesmo vetor com ele mesmo ? erro lógico.
        // Correto:
        if (p1->elementos[i] != p2->elementos[i]) {
            return false;
        }
    }

    return true;
}

void copiaPilha(Pilha *p1, Pilha *p2) {
    // [CORREÇÃO] Adicionado para limpar P2 antes de copiar.
    initPilha(p2);

    // [CORREÇÃO] Antes você comparava e fazia trocas desnecessárias de valores.
    // Correto: apenas copiar direto.
    for (int i = 0; i <= p1->topo; i++) {
        Push(p2, p1->elementos[i]);
    }
}

void InfoMatematicas(Pilha *p) {
    if (isEmpty(p)) {
        // [CORREÇÃO] Você tinha usado: if(isEmpty)
        // Esqueceu os parênteses e argumento ? causa erro de compilação.
        printf("Pilha vazia!\n");
        return;
    }

    int soma = 0, maior = p->elementos[0], menor = p->elementos[0];
    int pares = 0, impares = 0;
    int tam = Tamanho(p);

    for (int i = 0; i <= p->topo; i++) {
        int val = p->elementos[i];
        soma += val;
        if (val > maior) maior = val;
        if (val < menor) menor = val;
        if (val % 2 == 0) pares++;
        else impares++;
    }

    float media = (float)soma / tam;

    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);
    printf("Média: %.2f\n", media);
    printf("Quantidade de pares: %d\n", pares);
    printf("Quantidade de ímpares: %d\n", impares);
}

int main() {
    setlocale(LC_ALL, "");
    Pilha P1, P2;
    int opcao, valor;

    initPilha(&P1);
    initPilha(&P2);

    do {
        printf("\n===== MENU PILHAS =====\n");
        printf("1 - Inserir na P1\n");
        printf("2 - Inserir na P2\n");
        printf("3 - Remover da P1\n");
        printf("4 - Remover da P2\n");
        printf("5 - Listar elementos da P1\n");
        printf("6 - Listar elementos da P2\n");
        printf("7 - Ver topo da P1\n");
        printf("8 - Ver topo da P2\n");
        printf("9 - Comparar se as pilhas são iguais\n");
        printf("10 - Copiar P1 para P2\n");
        printf("11 - Informações matemáticas da P1\n");
        printf("12 - Informações matemáticas da P2\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor para inserir na P1: ");
                scanf("%d", &valor);
                Push(&P1, valor);
                break;

            case 2:
                printf("Digite um valor para inserir na P2: ");
                scanf("%d", &valor);
                Push(&P2, valor);
                break;

            case 3:
                pop(&P1);
                break;

            case 4:
                pop(&P2);
                break;

            case 5:
                listar(&P1);
                break;

            case 6:
                listar(&P2);
                break;

            case 7:
                valor = topo(&P1);
                if (valor != -1) printf("Topo da P1: %d\n", valor);
                break;

            case 8:
                valor = topo(&P2);
                if (valor != -1) printf("Topo da P2: %d\n", valor);
                break;

            case 9:
                if (Identicas(&P1, &P2)) {
                    printf("As pilhas são idênticas.\n");
                } else {
                    printf("As pilhas são diferentes.\n");
                    // [CORREÇÃO] Melhorado: agora diz qual é maior quando diferentes.
                    if (Tamanho(&P1) > Tamanho(&P2)) {
                        printf("P1 é maior.\n");
                    } else if (Tamanho(&P1) < Tamanho(&P2)) {
                        printf("P2 é maior.\n");
                    } else {
                        printf("São do mesmo tamanho, mas com valores diferentes.\n");
                    }
                }
                break;

            case 10:
                copiaPilha(&P1, &P2);
                printf("Elementos de P1 copiados para P2.\n");
                break;

            case 11:
                printf("Informações da P1:\n");
                InfoMatematicas(&P1);
                break;

            case 12:
                printf("Informações da P2:\n");
                InfoMatematicas(&P2);
                break;

            case 0:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}

