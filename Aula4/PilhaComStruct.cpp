#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tamanho 10

// Definindo a estrutura da pilha
typedef struct {
    int idade;
    int data;
    int matricula;
} Estrutura_pilha;

int topo = 0;

Estrutura_pilha pilha[tamanho];

// Função para retornar o tamanho da pilha
int Size_Pilha() {
    return topo;
}

// Função para adicionar um elemento na pilha
void Push(int valorIdade, int valorData, int valorMatricula) {
    if (topo < tamanho) {
        pilha[topo].idade = valorIdade;
        pilha[topo].data = valorData;
        pilha[topo].matricula = valorMatricula;
        topo++;
        printf("Inserção realizada com sucesso!\n\n\n");
    } else {
        printf("ERRO: A pilha já está cheia\n");
    }
}

// Função para remover um elemento da pilha
Estrutura_pilha Pop() {
    if (topo == 0) {
        printf("ERRO: Pilha encontra-se vazia\n");
        // Retorna um valor vazio para indicar erro
        Estrutura_pilha vazio = {0, 0, 0};
        return vazio;
    } else {
        topo--;
        return pilha[topo];
    }
}

// Função para listar os elementos da pilha
void Lista_Pilha() {
    printf("\n\nOs valores da pilha são:\n");
    for (int i = 0; i < topo; i++) {
        printf("Elemento na posição %i: \nIdade: %i\nData: %i\nMatricula: %i\n\n", 
                i + 1, pilha[i].idade, pilha[i].data, pilha[i].matricula);
    }
}

// Função para ver o topo da pilha
Estrutura_pilha Peek_Pilha() {
    if (topo > 0) {
        return pilha[topo - 1];
    }
    // Retorna um valor vazio se a pilha estiver vazia
    Estrutura_pilha vazio = {0, 0, 0};
    return vazio;
}

int main() {
    setlocale(LC_ALL, "portuguese");

    char op;
    int auxIdade, auxMatricula, auxData;

    printf("\n ###### Bem vindo ao nosso Sistema de Pilhas###### \n\n\n");

    while (op != 'S' && op != 's') {
        printf(" A - Adicionar um Elemento na Pilha\n");
        printf(" R - Remover um Elemento na Pilha\n");
        printf(" T - Tamanho atual da Pilha\n");
        printf(" L - Para listar os elementos da pilha\n");
        printf(" U - Para listar último elemento da pilha\n");
        printf(" S - Para sair\n");

        fflush(stdin);
        scanf("%c", &op);

        if (op == 'A' || op == 'a') {
            printf("\nInforme o valor de Idade que deseja inserir: ");
            scanf("%i", &auxIdade);

            printf("\nInforme o valor da Data que deseja inserir: ");
            scanf("%i", &auxData);

            printf("\nInforme o valor da Matricula que deseja inserir: ");
            scanf("%i", &auxMatricula);

            Push(auxIdade, auxData, auxMatricula);
        }

        else if (op == 'R' || op == 'r') {
            Estrutura_pilha removido = Pop();
            if (removido.idade != 0 || removido.data != 0 || removido.matricula != 0) {
                printf("O valor removido: \nIdade: %i\nData: %i\nMatricula: %i\n", 
                        removido.idade, removido.data, removido.matricula);
            }
        }

        else if (op == 'T' || op == 't') {
            printf("O tamanho da minha pilha é %i\n\n", Size_Pilha());
        }

        else if (op == 'L' || op == 'l') {
            Lista_Pilha();
        }

        else if (op == 'U' || op == 'u') {
            Estrutura_pilha topoPilha = Peek_Pilha();
            printf("\nO elemento do topo é: \nIdade: %i\nData: %i\nMatricula: %i\n\n", 
                    topoPilha.idade, topoPilha.data, topoPilha.matricula);
        }

        else {
            printf("\nATENÇÃO: Operação Inválida\n");
        }
    }

    return 0;
}

