#include "Grafo.h"

void initGrafo(Grafo *G)
{
    intitlist(&G->vertices);
}

short addVertice(Grafo *G)
{
    Vertice *new;
    intitlist(new);
    insertRight(new,&G->vertices);
}