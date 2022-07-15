#include <stdio.h>
#include "matriz_adj.c"
#include <stdbool.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int main()
{
    //getchar();
    TipoGrafo *JEnoi = (TipoGrafo*)malloc(sizeof(TipoGrafo));
    JEnoi->NumVertices = 5;
    JEnoi->NumArestas=0;
    FGVazio(JEnoi);
    Djecstra dij;

    InsereAresta(0,1,1,JEnoi);
    InsereAresta(1,0,3,JEnoi);
    InsereAresta(1,2,1,JEnoi);
    InsereAresta(2,4,1,JEnoi);
    InsereAresta(4,2,2,JEnoi);
    InsereAresta(2,3,2,JEnoi);
    InsereAresta(3,4,1,JEnoi);
    InsereAresta(3,0,5,JEnoi);

    /*if (ExisteAresta(0,8,JEnoi))
    {
        printf("Aresta tem o peso %d\n",ExisteAresta(0,8,JEnoi));
    }
    else
    {
        printf("Nao existe aresta\n");
    }*/
    
    
    ImprimeGrafo(JEnoi);
    printf("Valor djikstra de %d e igual a == %d\n", 0,dijkstra(*JEnoi,0,&dij));






    
   



    return 0;
}
