#include <stdio.h>
#include <stdlib.h>

typedef struct ed{
    struct e *ip; //priority
    struct e *in; //normal

    int topo;
    int *p; //stack
}ed;

typedef struct e{
    int n;
    struct e *prox;
}e;

ed *alocarestrutura();
void insert(ed *edx, int n);
void delete(ed *edx, int n);

int pilha, fila, filap;

int main(){
    ed *edx;
    int x, i, op, n;

    while(scanf("%d", &x) == 1){
        pilha=1;
        fila=1;
        filap=1;