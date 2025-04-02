#include <stdio.h>
#include <stdlib.h> // para alocação dinâmica
#include <string.h>

// Definição da estrutura do elemento da pilha
typedef struct Elemento {
    char *dado; // dado que quero colocar dentro da pilha
    struct Elemento *seguinte; // ponteiro para o próximo elemento da pilha
} Elemento;

// Definição da estrutura da pilha
typedef struct Pilha {
    Elemento *inicio; // ponteiro para o início da pilha (topo)
    int tamanho; // tamanho da pilha
} Pilha;

// Função para inicializar a pilha
void Init_Pilha(Pilha *pilha) {
    pilha->inicio = NULL; // a pilha começa vazia
    pilha->tamanho = 0;   // tamanho inicial da pilha é 0
}

// Função para adicionar um elemento à pilha (Push)
int Push_Pilha(Pilha *pilha, const char *texto) {
    Elemento *novo_elemento;

    // Aloca memória para o novo elemento
    if ((novo_elemento = (Elemento *)malloc(sizeof(Elemento))) == NULL)
        return -1; // falhou ao alocar memória

    // Aloca memória para armazenar o dado (texto)
    if ((novo_elemento->dado = (char *)malloc(10 * sizeof(char))) == NULL) {
        free(novo_elemento); // desaloca o elemento caso falhe alocar o dado
        return -1; // falhou ao alocar memória
    }

    // Copia o dado para o novo elemento
    strcpy(novo_elemento->dado, texto);

    // Coloca o novo elemento no topo da pilha
    novo_elemento->seguinte = pilha->inicio;
    pilha->inicio = novo_elemento;

    // Atualiza o tamanho da pilha
    pilha->tamanho++;

    return 0; // sucesso
}

// Função para remover um elemento da pilha (Pop)
int Pop_Pilha(Pilha *pilha) {
    if (pilha->tamanho == 0)
        return -1; // pilha vazia, não é possível remover

    // Remove o elemento do topo da pilha
    Elemento *remove_elemento = pilha->inicio;
    pilha->inicio = pilha->inicio->seguinte;

    // Libera a memória do dado e do elemento
    free(remove_elemento->dado);
    free(remove_elemento);

    // Atualiza o tamanho da pilha
    pilha->tamanho--;

    return 0; // sucesso
}

// Função para listar os elementos da pilha
void List_Pilha(Pilha *pilha) {
    Elemento *atual = pilha->inicio;

    printf("------- TOPO DA PILHA ----------\n");

    // Itera pela pilha e imprime os dados
    while (atual != NULL) {
        printf("  %s\n", atual->dado);
        atual = atual->seguinte;
    }

    printf("------- FUNDO DA PILHA ----------\n");
}

// Função principal
int main() {
    Pilha *teste1;
    char aux[11]; // buffer para armazenar a entrada do usuário
    int i;

    // Aloca memória para a pilha
    if ((teste1 = (Pilha *)malloc(sizeof(Pilha))) == NULL)
        return -1; // falha ao alocar memória para a pilha

    // Inicializa a pilha
    Init_Pilha(teste1);

    // Adiciona 3 elementos à pilha
    for (i = 0; i < 3; i++) {
        printf("Digite alguma coisa com até 10 caracteres: ");
        scanf("%10s", aux); // limita a entrada a 10 caracteres
        Push_Pilha(teste1, aux);
        printf("A pilha tem %i elementos.\n", teste1->tamanho);
        List_Pilha(teste1);
    }

    // Remove um elemento da pilha
    Pop_Pilha(teste1);
    printf("Agora a pilha tem %i elementos.\n", teste1->tamanho);
    List_Pilha(teste1);

    // Libera a memória da pilha
    free(teste1);

    return 0;
}

