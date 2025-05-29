#include <stdio.h>
#include <stdlib.h>

char vet[5] = {'A','B','C','D','E'};

// Corrigido: tipo void e matriz 5x5
void adicionarAresta(int matriz[5][5], int origem, int destino){
	matriz[origem][destino] = 1;
	matriz[destino][origem] = 1;
}

void imprimeMatriz(int matriz[5][5]){
    // Cabeçalho com as letras (colunas)
    printf("   ");  // espaço para alinhar com as letras da lateral
    for(int k = 0; k < 5; k++) {
        printf(" %c ", vet[k]);
    }
    printf("\n");
    
    // Para cada linha, imprime a letra da linha + valores da matriz
    for(int i = 0; i < 5; i++){
        printf(" %c ", vet[i]);  // letra lateral (índice da linha)
        for(int j = 0; j < 5; j++){
            printf(" %i ", matriz[i][j]);  // valores da linha
        }
        printf("\n");
    }
    printf("\n");
}


int main(){
    int matriz[5][5];

    // Inicializa a matriz com zeros (opcional, pois relacoes vai sobrescrever)
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            matriz[i][j] = 0;
        }
    }
    printf("\n");
    imprimeMatriz(matriz);
    
    adicionarAresta(matriz, 0, 1);
    adicionarAresta(matriz, 0, 2);
    
    adicionarAresta(matriz, 1, 2);
    adicionarAresta(matriz, 1, 3);
    
    adicionarAresta(matriz, 4, 2);
    
    imprimeMatriz(matriz);

    return 0;
}
