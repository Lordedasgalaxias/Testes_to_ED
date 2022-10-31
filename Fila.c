#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct nodo {
    char info [35];
    struct nodo * prox;

}nodo;

nodo * pushed(nodo * p, char * palavra){
    nodo * neww = (nodo *)malloc(sizeof(nodo));
    strcpy(neww->info,palavra);
    neww -> prox = p;
   return neww;

}

typedef struct Pilha{
    nodo * ultimo [10];
    int pos;
}Pilha;

Pilha *makePilha(){
    Pilha * nova = (Pilha *)malloc(sizeof(Pilha));
    for (nova->pos=0;nova->pos<10;nova->pos++){
        
        nova->ultimo[nova->pos] = (nodo*)malloc(sizeof(nodo));
        nova->ultimo[nova->pos]->prox = NULL;
    }
    nova->pos = 0;
    return nova;
}

Pilha * push (Pilha * p, char * info){  
    p->ultimo[p->pos]=pushed(p->ultimo[p->pos],info);
    p->pos++;
    return p;
}


int main(){
 char vetor[15];
   scanf("%s",vetor);
   Pilha * pe = makePilha();
 
   pe = push(pe,vetor);
   printf("%s",pe->ultimo[0]->info);

}
