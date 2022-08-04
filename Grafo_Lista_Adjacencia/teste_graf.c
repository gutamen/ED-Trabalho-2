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
    addAresta(&grafo,1,3,6);
    addAresta(&grafo,0,1,3);
    
    
    printGrafo(grafo);
    removeAresta(&grafo,0,2);

    printexistearesta(&grafo,0,3);
    printGrafo(grafo);
    printVerticeN(grafo,0);



    return 0;
}
