#define MAXNUMVERTICES 100
#define MAXNUMARESTAS  4500
#include <stdbool.h>
#define INFINITO  2147483647

typedef int TipoValorVertice;
typedef int TipoIndice;
typedef int TipoPeso;
typedef TipoPeso TipoValorAresta;
typedef struct ListaAdj
{
    TipoValorAresta list[MAXNUMVERTICES+1];
    unsigned NumVertices;
}ListaAdj;
typedef int TipoCor;
typedef int TipoValorTempo;
typedef struct TipoGrafo
{
    TipoPeso Mat[MAXNUMVERTICES+1][MAXNUMVERTICES+1];
    unsigned NumVertices;
    unsigned NumArestas;
}TipoGrafo;

typedef struct Djecstra
{
    int casa[MAXNUMVERTICES+1];
}Djecstra;


typedef struct TipoBuscaGrafo
{
    TipoCor  cor[MAXNUMVERTICES+1];
    unsigned NumVertices;
    unsigned NumArestas;
}TipoBuscaGrafo;

typedef int TipoApontador;

void FGVazio(TipoGrafo *Grafo);
void InsereAresta (TipoValorVertice V1, TipoValorVertice V2,TipoPeso Peso, TipoGrafo *Grafo);
TipoPeso ExisteAresta (TipoValorVertice Vertice1 ,TipoValorVertice Vertice2 , TipoGrafo *Grafo);
short ListaAdjVazia (TipoValorVertice Vertice , TipoGrafo *Grafo);
TipoApontador PrimeiroListaAdj ( TipoValorVertice *Vertice , TipoGrafo *Grafo);
void RetiraAresta (TipoValorVertice V1, TipoValorVertice V2,TipoPeso Peso, TipoGrafo *Grafo);
void ImprimeGrafo(TipoGrafo *Grafo);
int dijkstra(TipoGrafo grafo,TipoValorVertice vert,Djecstra *djanho);
