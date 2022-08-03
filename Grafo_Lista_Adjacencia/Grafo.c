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

short addAresta(Grafo *G,int vertice_1,int vertice_2,unsigned tamanho_aresta)   // adiciona uma aresta entre 2 vertices, necessario o tamanho
{
    if(tamanho_aresta != 0)
    {
        if(vertice_1 != vertice_2)
        {
            if(vertice_1<leghtList(G->vertices) && vertice_2<leghtList(G->vertices))
            {
                Tnode *aux2;
                Tnode *aux1;
                aux1=searchlistbyposi(vertice_1,&G->vertices);
                aux2=searchlistbyposi(vertice_2,&G->vertices);
                TlistSE *vert1 = aux1->info, *vert2 = aux2->info;
                insertRightifDistance(aux1->info, tamanho_aresta, vert2);
                insertRightifDistance(aux2->info, tamanho_aresta, vert1);
                return 0;
            }
            else
                printf("Vertice nao existente solicitada.\n");                  // caso vertice nao exista
        }
        else
        {
            printf("Impossivel inserir aresta com destino == origem.\n");       // caso tente fazer loop em um grafo nao direcionado
        }
    }
    else 
        printf("Tamanho == 0 nao eh permitido.\n");                             // caso a distancia seja == 0 nao existe distancia, tarefa impossivel
    return 1;




}


void printGrafo(Grafo grafo)                    // imprime cada vertice do grafo com suas respectivas arestas
{
    int l=0,i=0;
    Tnode *aux =grafo.vertices.first;
    if (aux == NULL)
        printf("Grafo vazio.\n");               // se o grafo esta vazio
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
            Tnode *aux3=searchlist(verticepointer,&grafo.vertices);
            j=searchposiinlist(aux3,&grafo.vertices);
            aux3=searchlist(aux2->info,&grafo.vertices);
            printf("\tAresta %d aponta para Vertice %d, Tamanho = %u\n",k,j,aux2->distancia);

            aux2=aux2->next;    
            k++;
        }
        printf("\n");
        aux=aux->next;
        i++;    
    }
}

Tnode* existearesta(Grafo *G, int vertice_1, int vertice_2)     // testa se existe aresta entre 2 vertices, retorna o nodo da aresta do vertice 1 caso exista
{
    Tnode *aux = searchlistbyposi(vertice_1,&G->vertices);
    TlistSE *vertice1 = aux->info;
    aux = searchlistbyposi(vertice_2,&G->vertices);
    Tnode *aux2 = vertice1->first;
    while (aux2)
    {
        if(aux2->info==aux->info)
            break;
        aux2=aux2->next;
    }
    return aux2;   
}


short removeAresta(Grafo *G,int vertice_1, int vertice_2)
{
    if(vertice_1<leghtList(G->vertices) && vertice_2<leghtList(G->vertices))
    {
        Tnode *aux = existearesta(G, vertice_1, vertice_2);
        Tnode *aux2 = existearesta(G, vertice_2, vertice_1);
        if(aux!=NULL)
        {
            Tnode *aux3 = searchlistbyposi(vertice_2,&G->vertices);
            TlistSE *vertice = aux3->info;
            removelist(searchposiinlist(aux2,vertice),vertice);
            aux3 = searchlistbyposi(vertice_1,&G->vertices);
            vertice = aux3->info;
            removelist(searchposiinlist(aux,vertice),vertice);
            return 0;
            
        }
        else
            printf("Tentativa de remocao invalida, nao existe aresta entre tais vertices.\n");
    }

    return 1;
}


void printexistearesta(Grafo *G, int vertice_1, int vertice_2)
{
    Tnode *aux2 = existearesta(G,vertice_1,vertice_2);
    if(aux2)
    {
        printf("Existe aresta entre os Vertices %d e %d,\nseu tamanho eh = %u\n",vertice_1,vertice_2,aux2->distancia);
    }
    else
    {
        printf("Nao existe aresta entre os Vertices %d e %d\n",vertice_1,vertice_2);
    }
}

short removeVertice(Grafo *G, unsigned vertice1)
{
    if(!emptylist(G->vertices))
    {
        Tnode *aux = searchlistbyposi(vertice1,&G->vertices);
        TlistSE *verticeL = aux->info;
        while(!emptylist(*verticeL))
        {
            Tnode *aux2 = G->vertices.first;
            int OndeVaiAresta=0;
            while(verticeL->first->info!=aux2->info && aux2)
            {
                aux2=aux2->next;
                OndeVaiAresta++;
            }
            removeAresta(G,vertice1,OndeVaiAresta);

            
        } 
        removelist(vertice1,&G->vertices);
    }
    else
        printf("Grafo Vazio.\n");
    return 0;

}