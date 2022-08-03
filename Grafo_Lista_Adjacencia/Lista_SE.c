// lista simplesmente encadeada


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "Lista_SE.h"
 

//========================================================
// function de lista encadeada
//======================================================== 


void intitlist(TlistSE *L)                  //inicialização da Lista
{
    L->first= NULL;
    L->last = NULL;
    L->lenght= 0;
}


void deletelist(TlistSE *L)                 //destruição da lista
{
    Tnode *p=L->first;
    while (p)
    {
       L->first=L->first->next;
       free(p);
       p=L->first;
    }
    L->lenght=0;
    L->last=NULL;

}


void printlist(TlistSE L)                   //impressao da lista
{
    Tnode *p = L.first;

    printf("[");
    while (p)
    {
        printf("%lld",p->info);
        if(p->next)
            printf(", ");
        p=p->next;
    }
    printf("]\n");

}


short insertLeft(Tdado x, TlistSE *L)       //insercao a esquerda          
{
    Tnode *aux;
    aux= (Tnode*)malloc(sizeof(Tnode));
    if(aux==NULL)
        return 1;                           // retorna 1 sinalizando falha na alocacao
                                            // lista orginal intacta
    else
    {
        aux->info = x;                      // insere o valor de x no node
        aux->next = L->first;               // insere o novo elemento antes do atual primeiro
        L->first = aux;                     // aux passa ser o primeiro
        if (L->last==NULL)                  // ajusta o ultimo
            L->last= aux;
        L->lenght++;                        // incrementa o numero de elementos
        return 0;
    }
}


short insertRight(Tdado x, TlistSE *L)      //insercao a direita
{
    Tnode *aux =(Tnode*)malloc(sizeof(Tnode));
    if(aux == NULL)
        return 1;                           //sinaliza erro de alocacao
    else
    {
        aux->info=x;
        aux->next=NULL;
        if(L->first==NULL)                  //lista vazia
            L->first=L->last=aux;           //first e last o mesmo node
        else
        {
            L->last->next=aux;
            L->last=aux;
        }
        L->lenght++;
        return 0;
    }
}



bool emptylist(TlistSE L)                   // verifica lista vazia
{
    return(L.lenght==0);
}


short leghtList(TlistSE L)                  //comprimento da lista
{
    return(L.lenght);
}


Tdado removeleft(TlistSE *L)                //remocao esquerda
{
    Tnode *aux = L->first;                  // node a ser removido
    Tdado Ret =aux->info;                   // info do dado a ser removido
    L->first=L->first->next;
    free(aux);
    L->lenght--;
    if(L->lenght==0)                        //lista vazia
        L->last=NULL;
    return Ret;
}


Tdado removeRight(TlistSE *L)               // remocao direita
{
    Tnode *aux = L->last;                   // node a ser removido
    Tdado ret = aux ->info;                 // INFO DO node a ser destruido

    if(L->first==L->last)
    {
        free(aux);
        L->first=L->last=NULL;
    }
    else
    {
        L->last=L->first;
        while (L->last->next!=aux)
        {
            L->last=L->last->next;
        }
        free(aux);

        L->last->next=NULL;
    }
    L->lenght--;
    return ret;
}

Tnode* searchlist( Tdado x, TlistSE *L)      //procura na lista
{
    Tnode *aux=L->first;
    while(aux && x != aux->info)
    {
        aux=aux->next;
    }
    return aux;
}

int searchposiinlist( Tnode *x, TlistSE *L)      //procura posição do nodo na lista
{
    Tnode *aux=L->first;
    int k=0;
    while(aux && x != aux)
    {
        aux=aux->next;
        k++;
    }
    if(k<L->lenght)
        return k;
    else
        return -1;
}

Tnode* searchlistbyposi( int posi , TlistSE *L)      //retorna endereço do Tnode na posição desejada 
{
    Tnode *aux=L->first;
    int i=0;
    while(aux && i < posi)
    {
        aux=aux->next;
        i++;
    }
    return aux;
}


int insertlist(Tdado x,unsigned p,TlistSE *L)//iserir no meio da lista
{
    if (p>L->lenght)
        return 1;
    else
    {
                                            // insercao na posicao 0
        if(p==0)
            return insertLeft(x,L);
        else if (p == L->lenght)            // insercao na ultima posicao
            return insertRight(x,L);
        else
        {
            Tnode *p1 =L->first,*aux;       // procurar pelo local da insercao
            unsigned i=0;
            aux= (Tnode*)malloc(sizeof(Tnode));
            if(!aux)
            {
                printf("ERRO nao foi possivel alocar\n");
                return 1;
            }
            while (++i<p)
            {
                p1=p1->next;
            }
            aux->info=x;
            aux->next=p1->next;
            p1->next=aux;
            L->lenght++;
            return 0;
        }
    }       
}


Tdado removelist(unsigned p,TlistSE *L)     //remover no meio da lista
{
    if (p>L->lenght)
    {                        // printa erro
        printf("Erro ao remover !!\n");
        return NULL;
    }
    else
    {
        if(p==0)                            // remover na posicao 0
            return removeleft(L);
        else if (p == L->lenght-1)          // remove na ultima posicao
            return removeRight(L);
        else
        {
            Tnode *p1 =L->first,*aux;       // procurar pelo local da remocao
            Tdado ret;
            unsigned i=0;
            while (++i<p)
            {
                p1=p1->next;
            }
            aux=p1->next;
            p1->next=aux->next;
            ret = aux->info;
            free(aux);
            L->lenght--;
            return ret;
        }
    }       
}


short insertRightifDistance(Tdado x,unsigned int distancia, TlistSE *L)      //insercao a direita com a distancia
{                                                                            //pensado para o vertice
    Tnode *aux =(Tnode*)malloc(sizeof(Tnode));
    if(aux == NULL)
        return 1;                           //sinaliza erro de alocacao
    else
    {
        aux->info=x;
        aux->next=NULL;
        if(L->first==NULL)                  //lista vazia
        {
            L->first=L->last=aux;           //first e last o mesmo node
            aux->distancia=distancia;
        }    
        else
        {
            L->last->next=aux;
            aux->distancia=distancia;
            L->last=aux;
        }
        L->lenght++;
        return 0;
    }
}



