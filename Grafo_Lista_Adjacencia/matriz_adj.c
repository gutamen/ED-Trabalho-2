#include <stdio.h>
#include "matriz_adj.h"
#include <stdbool.h>
#define TRUE 1
#define FALSE 0
#define preto 0
#define branco 1
#define cinza 2

void FGVazio(TipoGrafo *Grafo)
{ 
    short i , j ;
    for ( i = 0; i <= Grafo->NumVertices; i ++)
    {   
        for ( j = 0; j <=Grafo->NumVertices; j ++) Grafo->Mat[ i ] [ j ] = 0; 
    }
}

void InsereAresta (TipoValorVertice V1, TipoValorVertice V2,TipoPeso Peso, TipoGrafo *Grafo)
{ 
    Grafo->Mat[V1][V2] = Peso; 
    Grafo->NumArestas++;
}

TipoPeso ExisteAresta (TipoValorVertice Vertice1 ,TipoValorVertice Vertice2 , TipoGrafo *Grafo)
{ 
    
    return (Grafo->Mat[ Vertice1 ] [ Vertice2]);     
}

short ListaAdjVazia (TipoValorVertice Vertice , TipoGrafo *Grafo)
{ 
    TipoApontador Aux = 0;
    short ListaVazia = TRUE;
    while (Aux < Grafo->NumVertices && ListaVazia )
    if(Grafo->Mat[Vertice ] [Aux] > 0 ) ListaVazia = FALSE;
    else Aux++;
    return ( ListaVazia == TRUE );
}


TipoApontador PrimeiroListaAdj ( TipoValorVertice *Vertice , TipoGrafo *Grafo)
{ 
    TipoValorVertice Result;
    TipoApontador Aux = 0;
    short ListaVazia = TRUE;
    while (Aux < Grafo->NumVertices && ListaVazia )
    { 
        if(Grafo->Mat[*Vertice ] [Aux] > 0 ) { Result = Aux; ListaVazia = FALSE ; }
        else Aux++;
    }
    if (Aux == Grafo->NumVertices) printf( "Erro : Lista adjacencia vazia ( PrimeiroListaAdj )\n" );
    return Result;
}

void RetiraAresta (TipoValorVertice V1, TipoValorVertice V2,TipoPeso Peso, TipoGrafo *Grafo)
{ 
    if (Grafo->Mat[V1][V2] == 0 ) printf ( "Aresta nao existe \n" );
    else 
    { 
        Peso = Grafo->Mat[V1][V2]; 
        Grafo->Mat[V1][V2] = 0; 
        Grafo->NumArestas--;
    }
}

void LiberaGrafo (TipoGrafo *Grafo)
{ 
    /* Nao faz nada no caso de matrizes de adjacencia */ 
}

void ImprimeGrafo(TipoGrafo *Grafo)
{ 
    short i , j ; 
    printf ( "\t" );
    for ( i = 0; i <= Grafo->NumVertices -1; i ++) 
        printf ( "%3d\t" , i );
    printf ( " \n" );
    for ( i = 0; i <= Grafo->NumVertices -1; i ++)
    { 
        printf ( "%3d\t" , i );
        for ( j = 0; j <=Grafo->NumVertices - 1; j ++)
        printf ( "%3d\t" , Grafo->Mat[i][j] ) ;
        printf ( " \n" );
    }
}

void branqueiaculorido(TipoBuscaGrafo *CU,TipoGrafo *CU2)
{
    for(int i=0;CU2->NumVertices>i;i++)
    {
        CU->cor[i]=branco;
    }
}

/*TipoPeso buscaemprof(TipoGrafo *buscado, TipoValorVertice vertice_inicial, TipoValorVertice vertice_final)
{
    TipoBuscaGrafo *coro = (TipoBuscaGrafo*)malloc(sizeof(TipoBuscaGrafo));
    coro->NumVertices=buscado->NumVertices;
    branqueiaculorido(coro,buscado);
    if(ListaAdjVazia(vertice_inicial,buscado))
        return 0;
    else
    {
        coro->cor[vertice_inicial]=cinza;
        while(true)
        {
            bool criterio_parada=false;
            for(int j=0,criterio_parada=true;j<coro->NumVertices;j++)
            {
                if (coro->cor[j]!=preto)
                {
                    criterio_parada=false;
                }
                
            }
            if (criterio_parada==true)
            {
                break;
            }
            

        }    
    }
}*/

void PreencheAdj(ListaAdj *A,TipoGrafo B,TipoValorVertice C,int func)
{
    if(func == 0)
    {
        for(int i=0;i<B.NumVertices;i++)
        {
            A->list[i]=B.Mat[C][i];
            if(A->list[i]==0)
                A->list[i]=INFINITO;
        }
        A->NumVertices=B.NumVertices;
    }
    if (func==1)
    {
        for(int i=0;i<B.NumVertices;i++)
        {
            if(A->list[i]>B.Mat[C][i] && B.Mat[C][i]!=0)
                A->list[i]=B.Mat[C][i];
        }
        A->NumVertices=B.NumVertices;      
    }
    
}

TipoValorAresta VerificaPesoMin(ListaAdj A,int *pos,TipoBuscaGrafo grafi)
{
    TipoValorAresta Aux=INFINITO;
    for(int i =0; i<A.NumVertices;i++)
    {
        if(A.list[i]<Aux && grafi.cor[i]!=preto)
        {
            Aux=A.list[i];
            *pos=i;
        }
    }
    return Aux;
}

void PreencheINF(ListaAdj *A)
{
    for (int i=0;i<A->NumVertices;i++)
    {
        A->list[i]=INFINITO;
    }
}

int dijkstra(TipoGrafo grafo,TipoValorVertice vert,Djecstra *djanho)
{
    TipoBuscaGrafo grafi;
    int dist[MAXNUMVERTICES+1];
    ListaAdj dij;
    ListaAdj A;
    PreencheINF(&dij);
    PreencheAdj(&A,grafo,vert,0);
    int Pesos[MAXNUMVERTICES+1];
    for(int i=0;i<grafo.NumVertices;i++)
    {
        Pesos[i]=INFINITO;
    }
    branqueiaculorido(&grafi,&grafo);
    grafi.cor[vert]=preto;
    dij.list[vert]=0;
    djanho->casa[0]=vert;

    int parada=0;
    int casa=1;
    while(1)
    {
        TipoValorAresta aux;
        int pos=0;
        aux=VerificaPesoMin(A,&pos,grafi);
        //printf("%d\n",pos);
        PreencheAdj(&A,grafo,pos,1);
        grafi.cor[pos]=preto;
        djanho->casa[casa]=pos;
        dist[casa]=aux;
        casa++;
        parada++;
        
        if(parada==grafo.NumVertices-1)
            break;

    }
    int sum=0;
    for(int kk=0;kk<grafo.NumVertices;kk++)
        sum+=dist[kk];
    return sum;
}
