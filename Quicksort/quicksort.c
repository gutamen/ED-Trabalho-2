#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quickf.h"


int main()
{
	
	int tam, modo;
	srand(time(NULL));
	printf("Escolha o modo de execução (0 para automatico, 1 para manual) >> ");
	scanf("%d", &modo);
	puts("");
	if(modo==1){
		printf("Insira o tamanho do vetor a ser ordenado >> ");
		scanf("%d", &tam);
		puts("");
		int vet[tam+1];
	
		printf("Insira os valores do vetor:\n");

		insereVetor(tam,vet);
		
		// chamada do quicksort
		quick_sort(vet,0,tam-1);

	// mostra o vetor ordenado
		printVetor(tam,vet);
	}else{
		int vet1[10];
		insereVetorRandom(10,vet1);
		// chamada do quicksort
		quick_sort(vet1,0,9);

	// mostra o vetor ordenado
		printVetor(10,vet1);
	}
	
		
	return 0; 
}