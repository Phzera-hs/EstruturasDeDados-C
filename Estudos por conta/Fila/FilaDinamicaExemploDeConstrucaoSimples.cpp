#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

/* Vari�veis Globais */
int primeiro = 0;
int ultimo = -1;
int *Fila = NULL; // Ponteiro para a fila din�mica

void enqueue(int valor) {
    ultimo++;
    Fila = (int*) realloc(Fila, (ultimo + 1) * sizeof(int)); // Realoca espa�o
    if (Fila == NULL) {
        printf("Erro de aloca��o de mem�ria!\n");
        exit(1);
    }
    Fila[ultimo] = valor;
    printf("Valor inserido com sucesso!\n");
}

int dequeue() {
    int aux;
    if (primeiro <= ultimo) {
        aux = Fila[primeiro];
        primeiro++;
        return aux;
    } else {
        printf("A fila se encontra vazia.\n");
        return -1;
    }
}

void Listagem() {
    printf("#### OS ELEMENTOS DA FILA S�O ###\n");
    for (int i = primeiro; i <= ultimo; i++) {
        printf("Posi��o %d = %d\n", i - primeiro + 1, Fila[i]);
    }
    printf("\nCursor Primeiro �: %d", primeiro);
    printf("\nCursor �ltimo �: %d\n", ultimo);
}

int peek() {
    if (primeiro <= ultimo) {
        return Fila[primeiro];
    } else {
        return -1;
    }
}

int size() {
    return (ultimo - primeiro + 1);
}

void clear() {
    free(Fila);  // Libera toda a mem�ria alocada
    Fila = NULL; // Reseta o ponteiro
    primeiro = 0;
    ultimo = -1;
    printf("Fila limpa!\n");
}

int main() {
    setlocale(LC_ALL, ""); // Suporte a caracteres especiais

    char op;
    int novo;

    do {
        printf("\nI - Inserir um elemento na Fila\n");
        printf("R - Remover um elemento da Fila\n");
        printf("L - Listar os elementos da Fila\n");
        printf("V - Visualizar o primeiro elemento na Fila\n");
        printf("T - Tamanho da Fila\n");
        printf("D - Deletar(Limpar) todos os elementos da Fila\n");
        printf("E - Encerrar o programa\n");

        fflush(stdin);
        scanf("%c", &op);

        switch(op) {
            case 'I':
            case 'i':
                printf("Digite um valor para inserir na fila: ");
                scanf("%d", &novo);
                enqueue(novo);
                break;
            case 'R':
            case 'r':
                novo = dequeue();
                if (novo != -1) {
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
                if (novo != -1) {
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
                clear(); // Libera a mem�ria antes de sair
                break;
            default:
                printf("Op��o inv�lida! Tente novamente.\n");
        }
    } while (op != 'E' && op != 'e');

    return 0;
}

