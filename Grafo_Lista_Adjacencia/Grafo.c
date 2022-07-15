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

short addAresta(Grafo *G,int vert1,int vert2)
{
    
}

void errorPrinter(int code)
{

}