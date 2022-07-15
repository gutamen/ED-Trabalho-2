#include "Grafo.h"

void initGrafo(Grafo *G)
{
    intitlist(&G->vertices);
}

short addVertice(Grafo *G)
{
    if(emptylist(G->vertices))
    {
        Vertice *new;
        intitlist(new);
        insertRight(new,&G->vertices);
        return 0;
    }
    return 1;
}

short addAresta(Grafo *G,int vertice_1,int vertice_2,unsigned tamanho_aresta)
{
    Tnode *aux2;
    Tnode *aux1;
    aux1=searchlistbyposi(vertice_1,G->vertices);
    aux2=searchlistbyposi(vertice_2,G->vertices);





}

void errorPrinter(int code)
{

}