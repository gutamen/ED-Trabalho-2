#include <stdio.h>
#include "Grafo.h"
#include <stdbool.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int main()
{
    //getchar();
    Grafo grafo;
    initGrafo(&grafo);
    addVertice(&grafo);
    addVertice(&grafo);
    addVertice(&grafo);
    addVertice(&grafo);
    addAresta(&grafo,0,2,10);

    printGrafo(grafo);
   



    return 0;
}
