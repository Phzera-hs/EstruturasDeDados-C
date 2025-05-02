#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 10

// Função de comparação para qsort
int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void juntarEOrdenarFilas(int *Fila1, int *Fila2, int *FilaFinal, int tamanho) {
    int k = 0;

    // Copia os elementos da Fila1
    for (int i = 0; i < tamanho; i++) {
        FilaFinal[k++] = Fila1[i];
    }

    // Copia os elementos da Fila2
    for (int i = 0; i < tamanho; i++) {
        FilaFinal[k++] = Fila2[i];
    }

    // Ordena a FilaFinal
    qsort(FilaFinal, tamanho * 2, sizeof(int), comparar);
}

int main() {
    setlocale(LC_ALL, "");

    // Filas desordenadas
    int Fila1[MAX / 2] = {2,4,6,8,10};
    int Fila2[MAX / 2] = {1,3,5,7,9};
    int FilaFinal[MAX];

    printf("Fila 1:\n");
    for (int i = 0; i < MAX / 2; i++) {
        printf("[%d]", Fila1[i]);
    }

    printf("\n\nFila 2:\n");
    for (int i = 0; i < MAX / 2; i++) {
        printf("[%d]", Fila2[i]);
    }

    juntarEOrdenarFilas(Fila1, Fila2, FilaFinal, MAX / 2);

    printf("\n\nFila Final (Ordenada):\n");
    for (int i = 0; i < MAX; i++) {
        printf("[%d]", FilaFinal[i]);
    }

    return 0;
}

