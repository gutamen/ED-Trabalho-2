#include <stdio.h>
#include "Grafo.h"
#include <stdbool.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int main()
{
    int Op=0, param1=0 , param2=0, param3=0;
    Grafo grafo;
    initGrafo(&grafo);
    printf("Grafo inicializado !!\nPressione qualquer tecla\n");
    getchar();
    menu:
    system("clear");
    printf("\tSelecione a Opção:\n");
    printf("\t1 - Adicionar vertice\n");
    printf("\t2 - Adicionar aresta\n");
    printf("\t3 - Imprime Grafo\n");
    printf("\t4 - Verifica existencia de aresta\n");
    printf("\t5 - Remove aresta\n");
    printf("\t6 - Remove vertice\n");
    printf("\t7 - Imprime vertice\n");
    printf("\t8 - Destroi Grafo\n");
    printf("\t10 - Sair\n");
    param1=0 , param2=0, param3=0;
    scanf("%d",&Op);
    getchar();
    switch (Op)
    {
    case 1:
        system("clear");
        if(addVertice(&grafo))
            printf("\tErro ao inserir Vértice\n");
        else
            printf("\tVertice adicionada com sucesso\n");
        printf("Pressione Qualquer Tecla\n");
        getchar();
        goto menu;

    case 2:
        system("clear");
        printf("\tInsira os parâmetros para adicionar aresta\n\tVertice1, Vertice2, TamhanodaAresta\n");
        scanf("%d %d %d",&param1,&param2,&param3);
        getchar();
        if(addAresta(&grafo,param1,param2,param3))
            param3=0;
        else
            printf("\tAresta adicionada com sucesso\n");
        printf("Pressione Qualquer Tecla\n");
        getchar();
        goto menu;

    case 3:
        system("clear");
        printGrafo(grafo);
        printf("Pressione Qualquer Tecla\n");
        getchar();
        goto menu;

    case 4:
        system("clear");
        printf("\tInsira os parâmetros para verificar existencia aresta\n\tVertice1, Vertice2\n");
        scanf("%d %d",&param1,&param2);
        getchar();
        printexistearesta(&grafo,param1,param2);
        printf("Pressione Qualquer Tecla\n");
        getchar();
        goto menu;

    case 5:
        system("clear");
        printf("\tInsira os parâmetros para remover aresta\n\tVertice1, Vertice2\n");
        scanf("%d %d",&param1,&param2);
        getchar();
        if(removeAresta(&grafo,param1,param2))
            param3=0;
        else
            printf("\tAresta removida com sucesso\n");
        printf("Pressione Qualquer Tecla\n");
        getchar();
        goto menu;

    case 6:
        system("clear");
        printf("\tInsira o parâmetro para remover vertice\n\tVerticeparaRemover\n");
        scanf("%d",&param1);
        getchar();
        if(removeVertice(&grafo,param1))
            param3=0;
        else
            printf("\tVertice removida com sucesso\n");
        printf("Pressione Qualquer Tecla\n");
        getchar();
        goto menu;

    case 7:
        system("clear");
        printf("\tSelecione a vertice para impressao\n\tVerticeparaImpressao\n");
        scanf("%d",&param1);
        getchar();
        printVerticeN(grafo,param1);
        printf("Pressione Qualquer Tecla\n");
        getchar();
        goto menu;

    case 8:
        system("clear");
        DestroiGrafo(&grafo);
        printf("\tGrafo destruido\n");
        printf("Pressione Qualquer Tecla\n");
        getchar();
        goto menu;

    case 10:
        goto fim;

    default:
        printf("Opcao invalida selecionada\n");
        printf("Pressione Qualquer Tecla\n");
        getchar();
        goto menu;
    }
    fim:
    return 0;
}
