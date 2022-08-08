#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quickf.h"

void troca(int vet[], int a, int b)
{
	int aux = vet[a];
	vet[a] = vet[b];
	vet[b] = aux;
}

int particiona(int vet[], int first, int last)
{
	int pivo, pivos;
	
	pivo = vet[last]; //pivo recebe o ultimo valor
	pivos = first;
	
	for(int i=first;i<last;i++)
	{
		if(vet[i] <= pivo)
		{
			// realiza a troca
			troca(vet, i, pivos);
			// incrementa o pivo_indice
			pivos++;
		}
	}
	
	// troca o pivo
	troca(vet, pivos, last);
	
	// retorna o id do pivo
	return pivos;
}

// escolhe um pivo aleatorio para evitar o pior caso do quicksort
int particiona_random(int vet[], int first, int last)
{
	// seleciona um número entre fim (inclusive) e inicio (inclusive)
	int pivo = (rand() % (last - first + 1)) + first;
	
	// faz a troca para colocar o pivô no fim
	troca(vet, pivo, last);
	// chama a particiona
	return particiona(vet, first, last);
}

void quick_sort(int vet[], int first, int last)
{
	if(first < last)
	{
		//cria o pivo de forma aleatoria
		int pivo = particiona_random(vet, first, last);
		
		//chama o quick sort para os 
		quick_sort(vet, first, pivo - 1);
		quick_sort(vet, pivo + 1, last);
	}
}

void insereVetor(int tam, int vet[]){
	
	for(int i=0;i<tam;i++){
		printf("Valor %d >> ",i+1);
		scanf("%d",&vet[i]);
	}
}

void insereVetorRandom(int tam, int vet[]){
	
	for(int i=0;i<tam;i++){
		vet[i] = rand();
	}
}

void printVetor(int tam, int vet[]){
	for(short i = 0; i < tam; i++)
		printf("%d ", vet[i]);
	puts("");
}