#include <stdbool.h>

typedef long long int Tdado;              // define o tipo de dado dentro do node

typedef struct Tnode
{
    Tdado info;                 //dado armazenado no node
    unsigned distancia;
    struct Tnode *next;         //ponteiro para o proximo node
}Tnode;

typedef struct TlistSE          //define o node head da list
{
    Tnode *first;               // ponteiro para o primeiro elemento da lista
    unsigned lenght;            // numero de elementos armazendo
    Tnode *last;                // ponteiro para o ultimo elemento da lista
}TlistSE;


void intitlist(TlistSE *L);
void deletelist(TlistSE *L);
void printlist(TlistSE L);
short insertLeft(Tdado x, TlistSE *L);
short insertRight(Tdado x, TlistSE *L);
bool emptylist(TlistSE L);
short leghtList(TlistSE L);
Tdado removeleft(TlistSE *L);
Tdado removeRight(TlistSE *L);
Tnode* searchlist( Tdado x, TlistSE L);
int searchposiinlist( Tnode *x, TlistSE L);
Tnode* searchlistbyposi( int posi , TlistSE L);
int insertlist(Tdado x,unsigned p,TlistSE *L);
Tdado removelist(unsigned p,TlistSE *L);
short insertRightifDistance(Tdado x,unsigned distancia, TlistSE *L);

