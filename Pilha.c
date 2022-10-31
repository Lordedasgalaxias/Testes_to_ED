#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct jogos{
    char x[30];
    char y[30];
}jogos;


typedef struct nodo {
    char time1 [30];
    char time2 [30];
    struct nodo * prox;
} nodo;

typedef struct Fila {
    nodo * inicio;
    nodo * fim; 
}Fila;

Fila * makefila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = f->fim = NULL; 
    return f;
}

void push (Fila * p, char * t1, char * t2){
    if (p->inicio ==NULL && p->fim == NULL){
        nodo * novo = (nodo*)malloc(sizeof(nodo));
        strcpy(novo->time1,t1);
        strcpy(novo->time2,t2);

        novo->prox=NULL;
        p->inicio = p->fim = novo;
    }

    nodo * novo = (nodo*)malloc(sizeof(nodo));
    strcpy(novo->time1,t1);
    strcpy(novo->time2,t2);
    p->fim->prox=novo;
    p->fim=novo;

}

jogos * pop(Fila * p){
    jogos * aux = (jogos*) malloc(sizeof(jogos));
    strcpy(aux->x,p->inicio->time1);
    strcpy(aux->y,p->inicio->time2);
    nodo * bo = (nodo*)malloc(sizeof(nodo));
    bo->prox=p->inicio->prox;
    free(p->inicio);
    p->inicio=bo->prox;
    return aux;

}

int main(){
    /*char vetor[15];
    char vetow[15];
    Fila* pow = makefila();
    scanf("%s  %s",vetor,vetow);
    push(pow,vetor,vetow);
   printf("%s  %s",pow->inicio->time1,pow->inicio->time2);
    return 0;

        parte de teste */
         int k,n,z;
    
    char vector[30],vales[30];

    Fila * Fil = makefila();
    printf("digite o numero de times e potes\n");
    scanf("%d  %d",&k,&n);
    printf("digite os nomes dos times\n");
    for (z=0;z<k;z++){

        scanf("%s  %s",vector,vales);
        push(Fil,vector,vales);
        
       printf("\n %s  %s \n",Fil->inicio->time1,Fil->inicio->time2);
    }

    printf("\n\n%s  %s",Fil->fim->time1,Fil->fim->time2);


}
