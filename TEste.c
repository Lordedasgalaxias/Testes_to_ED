#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct jogos{
    char x[30];
    char y[30];
}jogos;


typedef struct nodof {
    char time1 [30];
    char time2 [30];
    struct nodof * prox;
} nodof;

typedef struct Fila {
    nodof * inicio;
    nodof * fim; 
}Fila;

Fila * makefila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = f->fim = NULL; 
    return f;
}

void pushf (Fila * p, char * t1, char * t2){
    if (p->inicio ==NULL && p->fim == NULL){
        nodof* novo = (nodof*)malloc(sizeof(nodof));
        strcpy(novo->time1,t1);
        strcpy(novo->time2,t2);

        novo->prox=NULL;
        p->inicio = p->fim = novo;
    }

    nodof* novo = (nodof*)malloc(sizeof(nodof));
    strcpy(novo->time1,t1);
    strcpy(novo->time2,t2);
    p->fim->prox=novo;
    p->fim=novo;

}

jogos * pop(Fila * p){
    jogos * aux = (jogos*) malloc(sizeof(jogos));
    strcpy(aux->x,p->inicio->time1);
    strcpy(aux->y,p->inicio->time2);
    nodof
 * bo = (nodof
*)malloc(sizeof(nodof
));
    bo->prox=p->inicio->prox;
    free(p->inicio);
    p->inicio=bo->prox;
    return aux;

}


//////*                                                          *//////
/////* //*/*/*/*/*/*/*/*//*/*/*/*/*/***/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/

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
    nodo * ultimo [50];
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

void popP(Pilha * PI, Fila *fila, int k, int n){
    int aux,au;
    char vaux1[30],vaux2[30];
    nodo * neww = (nodo *)malloc(sizeof(nodo));
    nodo * nelw = (nodo *)malloc(sizeof(nodo));
    for(aux=0;aux<= k;aux++){
        if (aux==n){aux = 0;}
        
        strcpy(vaux1,PI->ultimo[aux]->info);
        neww = PI ->ultimo[aux]->prox;
        pushf(fila,PI ->ultimo[aux]->info,PI->ultimo[(aux+au)]->info);
        free(PI->ultimo[aux]);
        PI->ultimo[aux] = neww;

        aux++;
        
        strcpy(vaux2,PI->ultimo[aux]->info);
        nelw ->prox = PI ->ultimo[aux]->prox;
        pushf(fila,PI ->ultimo[aux]->info,PI->ultimo[(aux+au)]->info);
        free(PI->ultimo[aux]);
        PI->ultimo[aux] = nelw;
    }

    /*for(aux=0;aux<= k;aux++){
        pushf(fila,PI ->ultimo[aux]->info,PI->ultimo[(aux+au)]->info);
    }
*/
}


/**main**/

int main(){
    
    int k,n,z;
    
    char vector[30];
    Pilha * pote = makePilha();

    Fila * Fil = makefila();
    printf("digite o numero de times e potes\n");
    scanf("%d  %d",&k,&n);
    printf("digite os nomes dos times\n");
    for (z=0;z<k;z++){

        scanf("%s",vector);
        if((pote->pos-1)==n){
        pote->pos = 0;
        pote ->ultimo[pote->pos]= push(pote,vector);
        }

        pote ->ultimo[pote->pos] = push(pote,vector);
    }

    popP(pote,Fil,k,n);
    
    printf("\n %s  %s ",Fil->inicio->time1,Fil->inicio->time2);
    
    
    return 0;
}

