#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    int id;
    char nome[50];
    int documento;
    int idade;
} Pessoa;

typedef struct Elemento {
    Pessoa dados;
    struct Elemento *prox;
} Elemento;

typedef struct {
    Elemento *inicio;
    Elemento *final;
} Fila;

// Inicializa a fila
void inicializarFila(Fila *fi) {
    fi->inicio = NULL;
    fi->final = NULL;
}

int enqueue(Fila *fi, Pessoa pessoa) {
    if (fi == NULL) return 0;

    Elemento *no = (Elemento *)malloc(sizeof(Elemento));
    if (no == NULL) return 0;

    no->dados = pessoa;
    no->prox = NULL;

    if (fi->final == NULL) {
        fi->inicio = no;
    } else {
        fi->final->prox = no;
    }
    fi->final = no;
    return 1;
}

int dequeue(Fila *fi, Pessoa *removido) {
    if (fi == NULL || fi->inicio == NULL) return 0;

    Elemento *no = fi->inicio;
    *removido = no->dados;
    fi->inicio = no->prox;
    if (fi->inicio == NULL)
        fi->final = NULL;
    free(no);
    return 1;
}

void listar(Fila fi) {
    Elemento *aux = fi.inicio;
    printf("\nFila atual:\n");
    while (aux != NULL) {
        printf("ID: %d | Nome: %s | Documento: %d | Idade: %d\n", 
               aux->dados.id, aux->dados.nome, aux->dados.documento, aux->dados.idade);
        aux = aux->prox;
    }
}

void reverso(Fila *fi) {
    if (fi == NULL || fi->inicio == NULL) return;

    Elemento *prev = NULL;
    Elemento *current = fi->inicio;
    Elemento *next = NULL;

    fi->final = fi->inicio; // O antigo início vira o final

    while (current != NULL) {
        next = current->prox;
        current->prox = prev;
        prev = current;
        current = next;
    }
    fi->inicio = prev;
}

void limparFila(Fila *fi) {
    Pessoa temp;
    while (dequeue(fi, &temp));
}

int tamanhoFila(Fila fi) {
    int cont = 0;
    Elemento *aux = fi.inicio;
    while (aux != NULL) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

int main() {
    setlocale(LC_ALL, "");

    Fila fi;
    inicializarFila(&fi);

    Pessoa pessoa, removida;
    int id = 1;
    char op;

    do {
        printf("\nMenu:\n");
        printf("I - Inserir um elemento na Fila\n");
        printf("R - Remover um elemento da Fila\n");
        printf("L - Listar os elementos da Fila\n");
        printf("V - Visualizar o primeiro elemento na Fila\n");
        printf("T - Tamanho da Fila\n");
        printf("D - Deletar todos os elementos da Fila\n");
        printf("X - Inverter a fila (Reverso)\n");
        printf("E - Encerrar o programa\n");

        fflush(stdin);
        scanf(" %c", &op);

        switch (op) {
            case 'I':
            case 'i':
                printf("Digite o nome da pessoa: ");
                fflush(stdin);
                gets(pessoa.nome);

                printf("Digite o número do documento: ");
                scanf("%d", &pessoa.documento);

                printf("Digite a idade: ");
                scanf("%d", &pessoa.idade);

                pessoa.id = id++;
                enqueue(&fi, pessoa);
                break;

            case 'R':
            case 'r':
                if (dequeue(&fi, &removida)) {
                    printf("Pessoa removida: %s\n", removida.nome);
                } else {
                    printf("Fila vazia.\n");
                }
                break;

            case 'L':
            case 'l':
                listar(fi);
                break;

            case 'V':
            case 'v':
                if (fi.inicio != NULL) {
                    printf("Primeiro da fila: %s\n", fi.inicio->dados.nome);
                } else {
                    printf("Fila vazia!\n");
                }
                break;

            case 'T':
            case 't':
                printf("Tamanho da fila: %d\n", tamanhoFila(fi));
                break;

            case 'D':
            case 'd':
                limparFila(&fi);
                printf("Fila limpa!\n");
                break;

            case 'X':
            case 'x':
                reverso(&fi);
                printf("Fila invertida com sucesso!\n");
                break;

            case 'E':
            case 'e':
                limparFila(&fi);
                printf("Encerrando...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (op != 'E' && op != 'e');

    return 0;
}

