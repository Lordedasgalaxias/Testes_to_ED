#include<stdio.h>
#include <stdlib.h>

typedef struct nodo {
    char vetor[30];
    struct nodo * prox;
} nodo;

typedef struct Pilha{
    nodo * prim;
}Pilha;

int main (){

char p[30];
int k,i;
scanf("%d", &k);
nodo *pote= (nodo*)malloc(k * sizeof(nodo));
for (i=0;i<k;i++){
        scanf("%s\n",(pote+i) -> vetor);

}
printf("%s", (pote + 3)-> vetor);

}







