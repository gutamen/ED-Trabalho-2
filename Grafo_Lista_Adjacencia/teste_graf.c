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
    
    printGrafo(grafo);
    addVertice(&grafo);
    addVertice(&grafo);
    addVertice(&grafo);
    addVertice(&grafo);
    addAresta(&grafo,0,2,10);
    addAresta(&grafo,1,3,6);
    addAresta(&grafo,0,1,3);
    
    
    printGrafo(grafo);
   
    printexistearesta(&grafo,0,3);

    removeVertice(&grafo,0);
    removeVertice(&grafo,1);

    printGrafo(grafo);


    return 0;
}
