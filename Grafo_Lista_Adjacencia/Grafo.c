#include "Grafo.h"

void initGrafo(Grafo *G)
{
    intitlist(&G->vertices);
}

short addVertice(Grafo *G)
{

    Vertice *new=(Vertice*)malloc(sizeof(Vertice));
    intitlist(&new->arestas);
    insertRight(new,&G->vertices);
    return 0;
    

}

short addAresta(Grafo *G,int vertice_1,int vertice_2,unsigned tamanho_aresta)
{

    if(vertice_1<leghtList(G->vertices) && vertice_2<leghtList(G->vertices))
    {
        Tnode *aux2;
        Tnode *aux1;
        aux1=searchlistbyposi(vertice_1,G->vertices);
        aux2=searchlistbyposi(vertice_2,G->vertices);
        TlistSE *vert1 = aux1->info, *vert2 = aux2->info;
        insertRightifDistance(aux1->info, tamanho_aresta, vert2);
        insertRightifDistance(aux2->info, tamanho_aresta, vert1);
        return 0;
    }

    return 1;




}

void printGrafo(Grafo grafo)
{
    int l=0,i=0;
    Tnode *aux =grafo.vertices.first;
    while(aux)
    {
        int k=0;
        long long int listavertice = aux->info;
        TlistSE *aresta = listavertice;
        Tnode *aux2 = aresta->first;
        printf("Vertice %d\n", i);
        while(aux2)
        {
            int j=0;
            long long int verticepointer=aux2->info;
            Tnode *aux3=searchlist(verticepointer,grafo.vertices);
            j=searchposiinlist(aux3,grafo.vertices);
            aux3=searchlist(aux2->info,grafo.vertices);
            printf("Aresta %d aponta para Vertice %d, Tamanho = %u\n",k,j,aux2->distancia);

            aux2=aux2->next;    
        }
        printf("\n");
        aux=aux->next;
        i++;
        
    }
}

void errorPrinter(int code)
{

}