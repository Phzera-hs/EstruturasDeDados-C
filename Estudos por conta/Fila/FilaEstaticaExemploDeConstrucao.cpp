#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>

#define MAX 3

/* CRIANDO FILA ESTÁTICA */
typedef struct {
    int matricula;
    char nome[30];
    float n1, n2, n3;
} Aluno; // Alunos que quero inserir na fila (pode ser qualquer outra coisa)

typedef struct {
    int inicio, final, qntd;
    Aluno dados[MAX];
} Fila; // Estrutura da fila. OBRIGATÓRIO essas variáveis (Aluno pode ser qualquer outra coisa)

Fila* cria_Fila() {
    Fila *fi = (Fila*)malloc(sizeof(Fila));
    if (fi != NULL) {
        fi->inicio = 0;
        fi->final = 0;
        fi->qntd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi) {
    free(fi);
}

// Funções de manipulação da fila

int tamanho_Fila(Fila* fi) {
    if (fi == NULL) {
        return -1;
    }
    return fi->qntd;
}

int Fila_cheia(Fila* fi) {
    if (fi == NULL) {
        return -1;
    }
    if (fi->qntd == MAX) {
        return 1; // Fila cheia
    } else {
        return 0; // Fila não cheia
    }
}

int Fila_vazia(Fila* fi) {
    if (fi == NULL)
        return -1;
    if (fi->qntd == 0)
        return 1;    // Fila vazia
    else
        return 0; // Fila não é vazia
}

int insere_Fila(Fila* fi, Aluno aluno) {
    if (fi == NULL) {
        return 0;
    }
    if (Fila_cheia(fi)) {
        return 0;
    }
    fi->dados[fi->final] = aluno;
    fi->final = (fi->final + 1) % MAX; // %MAX garante que volte para o início
    fi->qntd++;
    return 1;
}

int consulta_Fila(Fila* fi, Aluno* aluno) {
    if (fi == NULL || Fila_vazia(fi)) {
        return 0;
    }
    *aluno = fi->dados[fi->inicio];
    return 1;
}

int remove_Fila(Fila* fi) {
    if (fi == NULL || Fila_vazia(fi)) {
        return 0;
    }
    fi->inicio = (fi->inicio + 1) % MAX;
    fi->qntd--;
    return 1;
}

// Função para imprimir os dados dos alunos na fila
void imprime_Fila(Fila* fi) {
    if (fi == NULL || Fila_vazia(fi)) {
        printf("Fila vazia ou inexistente.\n");
        return;
    }

    int i = fi->inicio;
    for (int cont = 0; cont < fi->qntd; cont++) {
        printf("\nAluno %d:\n", cont + 1);
        printf("Nome: %s\n", fi->dados[i].nome);
        // Caso queira exibir matrícula e notas, descomente as linhas abaixo
        // printf("Matrícula: %d\n", fi->dados[i].matricula);
        // printf("Notas: %.2f, %.2f, %.2f\n", fi->dados[i].n1, fi->dados[i].n2, fi->dados[i].n3);

        i = (i + 1) % MAX;  // andar circular
    }
}

int main() {
    setlocale(LC_ALL, ""); // Configuração para suportar caracteres especiais

    Fila *fila;
    char op;
    Aluno aluno;
    int x;

    fila = cria_Fila();

    // Loop de interação com o menu
    do {
        // Exibe o menu de opções
        printf("\nMENU\n");
        printf("I - Inserir um aluno na Fila\n");
        printf("R - Remover um aluno da Fila\n");
        printf("L - Listar os alunos da Fila\n");
        printf("V - Consultar o primeiro aluno na Fila\n");
        printf("C - Consultar o tamanho da Fila\n");
        printf("E - Encerrar o programa\n");

        fflush(stdin); // Limpa o buffer de entrada
        scanf("%c", &op); // Lê a opção do usuário

        switch (op) {
            case 'I':
            case 'i':
                if (Fila_cheia(fila)) {
                    printf("Fila cheia! Não é possível inserir mais alunos.\n");
                } else {
                    // Solicita os dados do aluno
                    printf("Digite o nome do aluno: ");
                    scanf("%s", aluno.nome);
                    printf("Digite a matrícula do aluno %s: ", aluno.nome);
                    scanf("%d", &aluno.matricula);
                    printf("Digite a nota 1 do aluno %s: ", aluno.nome);
                    scanf("%f", &aluno.n1);
                    printf("Digite a nota 2 do aluno %s: ", aluno.nome);
                    scanf("%f", &aluno.n2);
                    printf("Digite a nota 3 do aluno %s: ", aluno.nome);
                    scanf("%f", &aluno.n3);

                    // Insere o aluno na fila
                    x = insere_Fila(fila, aluno);
                    if (x) {
                        printf("Aluno inserido com sucesso!\n");
                    } else {
                        printf("Falha ao inserir aluno.\n");
                    }
                }
                break;

            case 'R':
            case 'r':
                x = remove_Fila(fila);
                if (x) {
                    printf("Aluno removido com sucesso!\n");
                } else {
                    printf("Falha ao remover aluno. A fila pode estar vazia.\n");
                }
                break;

            case 'L':
            case 'l':
                imprime_Fila(fila);
                break;

            case 'V':
            case 'v':
                x = consulta_Fila(fila, &aluno);
                if (x) {
                    printf("Primeiro aluno da fila: %s\n", aluno.nome);
                } else {
                    printf("Fila vazia.\n");
                }
                break;

            case 'C':
            case 'c':
                printf("Tamanho da fila: %d\n", tamanho_Fila(fila));
                break;

            case 'E':
            case 'e':
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (op != 'E' && op != 'e'); // Continua até o usuário escolher 'E' para encerrar

    libera_Fila(fila); // Libera a memória da fila ao final
    return 0;
}

