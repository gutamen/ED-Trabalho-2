#include <stdio.h>
#include "Grafo.h"
#include <stdbool.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int main()
{

    Grafo *grafo = (Grafo*)malloc(sizeof(Grafo)); 
    initGrafo(grafo);
    //system("clear");
    printf("\tGrafo inicializado\n\n");
    if(addVertice(grafo))
    {
        printf("\tErro ao inserir vertice\n");
    }
    else
    {
        printf("\tVertice inserida\n");
    }
    if(addVertice(grafo))
    {
        printf("\tErro ao inserir vertice\n");
    }
    else
    {
        printf("\tVertice inserida\n");
    }
    if(addVertice(grafo))
    {
        printf("\tErro ao inserir vertice\n");
    }
    else
    {
        printf("\tVertice inserida\n");
    }
    if(addVertice(grafo))
    {
        printf("\tErro ao inserir vertice\n");
    }
    else
    {
        printf("\tVertice inserida\n");
    }
    if(addVertice(grafo))
    {
        printf("\tErro ao inserir vertice\n");
    }
    else
    {
        printf("\tVertice inserida\n");
    }
    if(addVertice(grafo))
    {
        printf("\tErro ao inserir vertice\n");
    }
    else
    {
        printf("\tVertice inserida\n\n");
    }
   
    printexistearesta(grafo,0,2);
    if(addAresta(grafo,0,2,10))
    {
        printf("\tErro ao inserir aresta\n");
    }
    else
    {
        printf("\tAresta inserida\n");
    }
    printexistearesta(grafo,0,2);
    

    if(addAresta(grafo,1,2,3))
    {
        printf("\tErro ao inserir aresta\n");
    }
    else
    {
        printf("\tAresta inserida\n");
    }

    if(addAresta(grafo,0,3,2))
    {
        printf("\tErro ao inserir aresta\n");
    }
    else
    {
        printf("\tAresta inserida\n");
    }
    
    
    if(addAresta(grafo,1,3,11))
    {
        printf("\tErro ao inserir aresta\n");
    }
    else
    {
        printf("\tAresta inserida\n");
    }

    if(addAresta(grafo,4,5,8))
    {
        printf("\tErro ao inserir aresta\n");
    }
    else
    {
        printf("\tAresta inserida\n");
    }

    if(addAresta(grafo,5,3,16))
    {
        printf("\tErro ao inserir aresta\n");
    }
    else
    {
        printf("\tAresta inserida\n");
    }
    
    if(addAresta(grafo,4,3,1))
    {
        printf("\tErro ao inserir aresta\n");
    }
    else
    {
        printf("\tAresta inserida\n");
    }

    
    printf("Menor aresta eh %d\n",menorAresta(*grafo));
    printVerticeN(*grafo,3);

    if(removeAresta(grafo,4,3))
    {
        printf("Erro ao remover Aresta\n");
    }
    else
        printf("Aresta Removida\n");

    printVerticeN(*grafo,3);

    printGrafo(*grafo);

    if(removeVertice(grafo,3))
    {
        printf("Erro ao remover Vertice\n");
    }
    else
        printf("Vertice removida\n");

    printGrafo(*grafo);

    if(removeVertice(grafo,5))
    {
        printf("Erro ao remover Vertice\n");
    }
    else
        printf("Vertice removida\n");


    DestroiGrafo(grafo);
    printf("Grafo destruido\n");

    printGrafo(*grafo);



    return 0;
}
