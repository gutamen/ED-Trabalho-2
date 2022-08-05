#include <stdio.h>
#include <stdlib.h>
#include "Lista_SE.h"


typedef struct Vertice
{
    TlistSE arestas;                // lista de arestas para cada vertice
}Vertice;


typedef struct Grafo
{
    TlistSE vertices;               // lista de vertices do grafo
}Grafo;

void initGrafo(Grafo *G);
bool GrafoVazio(Grafo G);
int addVertice(Grafo *G);
int addAresta(Grafo *G,int vertice_1,int vertice_2,int tamanho_aresta);
void printGrafo(Grafo grafo);
Tnode* existearesta(Grafo *G, int Vertice_1, int Vertice_2);
int removeAresta(Grafo *G,int vertice_1, int vertice_2);
void printexistearesta(Grafo *G, int vertice_1, int vertice_2);
int removeVertice(Grafo *G, int vertice);
void printVerticeN(Grafo grafo, int vertice);