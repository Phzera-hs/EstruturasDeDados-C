#include <stdio.h>
#include <stdlib.h> // para aloca��o din�mica
#include <string.h>

// Defini��o da estrutura do elemento da pilha
typedef struct Elemento {
    char *dado; // dado que quero colocar dentro da pilha
    struct Elemento *seguinte; // ponteiro para o pr�ximo elemento da pilha
} Elemento;

// Defini��o da estrutura da pilha
typedef struct Pilha {
    Elemento *inicio; // ponteiro para o in�cio da pilha (topo)
    int tamanho; // tamanho da pilha
} Pilha;

// Fun��o para inicializar a pilha
void Init_Pilha(Pilha *pilha) {
    pilha->inicio = NULL; // a pilha come�a vazia
    pilha->tamanho = 0;   // tamanho inicial da pilha � 0
}

// Fun��o para adicionar um elemento � pilha (Push)
int Push_Pilha(Pilha *pilha, const char *texto) {
    Elemento *novo_elemento;

    // Aloca mem�ria para o novo elemento
    if ((novo_elemento = (Elemento *)malloc(sizeof(Elemento))) == NULL)
        return -1; // falhou ao alocar mem�ria

    // Aloca mem�ria para armazenar o dado (texto)
    if ((novo_elemento->dado = (char *)malloc(10 * sizeof(char))) == NULL) {
        free(novo_elemento); // desaloca o elemento caso falhe alocar o dado
        return -1; // falhou ao alocar mem�ria
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

// Fun��o para remover um elemento da pilha (Pop)
int Pop_Pilha(Pilha *pilha) {
    if (pilha->tamanho == 0)
        return -1; // pilha vazia, n�o � poss�vel remover

    // Remove o elemento do topo da pilha
    Elemento *remove_elemento = pilha->inicio;
    pilha->inicio = pilha->inicio->seguinte;

    // Libera a mem�ria do dado e do elemento
    free(remove_elemento->dado);
    free(remove_elemento);

    // Atualiza o tamanho da pilha
    pilha->tamanho--;

    return 0; // sucesso
}

// Fun��o para listar os elementos da pilha
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

// Fun��o principal
int main() {
    Pilha *teste1;
    char aux[11]; // buffer para armazenar a entrada do usu�rio
    int i;

    // Aloca mem�ria para a pilha
    if ((teste1 = (Pilha *)malloc(sizeof(Pilha))) == NULL)
        return -1; // falha ao alocar mem�ria para a pilha

    // Inicializa a pilha
    Init_Pilha(teste1);

    // Adiciona 3 elementos � pilha
    for (i = 0; i < 3; i++) {
        printf("Digite alguma coisa com at� 10 caracteres: ");
        scanf("%10s", aux); // limita a entrada a 10 caracteres
        Push_Pilha(teste1, aux);
        printf("A pilha tem %i elementos.\n", teste1->tamanho);
        List_Pilha(teste1);
    }

    // Remove um elemento da pilha
    Pop_Pilha(teste1);
    printf("Agora a pilha tem %i elementos.\n", teste1->tamanho);
    List_Pilha(teste1);

    // Libera a mem�ria da pilha
    free(teste1);

    return 0;
}

