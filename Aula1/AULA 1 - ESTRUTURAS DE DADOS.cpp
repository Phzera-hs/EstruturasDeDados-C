#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>


/**/

int max = 10;

int main(){
setlocale (LC_ALL, "");

int vetor[] = { 51,33,16,4,66,70,32,12,13,41 };
int i,j, aux;
int qntdSwaps = 0, qntdLoops = 0, buscado, posicao;
bool encontrado = false;

	for (i = max-1; i>0; i--){
		for(j=0; j<i; j++){	
			if(vetor[j]> vetor[j+1]){
				aux = vetor[j+1];
				vetor[j+1]= vetor[j];
				vetor[j]= aux;
				qntdSwaps++;	
			}
			qntdLoops++;
		}
	}
	
	for(i = 0; i < max; i++){
		printf("[ %i ] ", vetor[i]);
	}	
	printf("\nQuantidade de loops: %i", qntdLoops);
	printf("\nQuantidade de mudanças (swaps): %i", qntdSwaps);
	
	
		printf("\n\nDigite um número para buscar dentro do vetor: ");
	scanf("%i", &buscado);
	
	for(i = 0; i < max; i++)
	{
		if(buscado == vetor[i])
		{
			 encontrado = true;
			 posicao = i+1;
		}
		break;
	}
	(encontrado) ? printf("Valor %i encontrado na posição %i!", buscado, posicao) :	printf("Valor %i não encontrado!!", buscado);
// (CONDICAO) ? [VERDADEIRO] : [FALSO]	
}	

