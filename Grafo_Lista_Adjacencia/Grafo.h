#include <stdio.h>
#include <stdlib.h>
#include "Lista_SE.h"


typedef struct Vertice
{
    TlistSE arestas;
}Vertice;


typedef struct Grafo
{
    TlistSE vertices; 
}Grafo;

void initGrafo(Grafo *G);
short addVertice(Grafo *G);
short addAresta(Grafo *G,int vertice_1,int vertice_2,unsigned tamanho_aresta);
void printGrafo(Grafo grafo);