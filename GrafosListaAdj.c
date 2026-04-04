#include "GLista.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


void initialize(VERTEX *g, int v){
    int i;
    for(i = 0; i < v; i++){
        g[i].start = NULL;
    }
}


bool edgeExists(VERTEX *g, int v1, int v2){
    NODE *p = g[v1].start;

    while(p){
        if(p->adj == v2) return true;
        p = p->next;
        }
        return false;
}


bool addEdge(VERTEX *g, int v1, int v2){
    if(edgeExists(g, v1, v2)){
        return false;
    }
    NODE *new = (NODE *) malloc(sizeof(NODE));
    new->adj = v2;
    new->next = g[v1].start;
    g[v1].start = new;
    
    return true;
}


bool deleteEdge(VERTEX *g, int v1, int v2){
    NODE *prev = NULL;
    NODE *p = g[v1].start;

    while(p){
        if(p->adj == v2) break;
        prev = p;
        p = p->next;
    }
    if(!p){
        return false;
    }

    if(prev){
        prev->next = p->next;
    }else{
        g[v1].start = p->next;
    }

    free(p);
    return true;
}


void printG(VERTEX *g, int v){
    int i;
    for(i = 0; i < v; i++){
        printf("%d", i);
        NODE *p = g[i].start;
        while(p){
            printf(" -> %d", p->adj);
            p = p->next;
        }
        printf("\n");
    }
    printf("\n");
}


bool verifySubG(VERTEX *g, VERTEX *gz, int v){
    int i;
    for(i = 0; i < v; i++){
        NODE *p = g[i].start;
        while(p){
            if(!edgeExists(g, i, p->adj)) return false;
            p = p->next;
        }
    }
    return true;
}

void resetFlags(VERTEX *g, int v){
    int i;
    for(i = 0; i < v; i++){
        g[i].flag = 0;
    }
}


VERTEX *transpose(VERTEX *g, int v){
    VERTEX *gt = malloc(v * sizeof(VERTEX));

    initialize(gt, v);
    int i;
    for(i = 0; i < v; i++){
        NODE *p = g[i].start;
        while(p){
            NODE *new = malloc(sizeof(NODE));
            new->adj = i;
            new->next = gt[p->adj].start;
            gt[p->adj].start = new;
            p = p->next;
        }
    }
    return gt;
}

void deep(VERTEX *g ,int i){
    g[i].flag = 1;
    NODE *p = g[i].start;
    
    while(p){
        if(g[p->adj].flag == 0) deep(g, p->adj);

        p = p->next;
    }
    g[i].flag == 2;
}

void deepAgain(VERTEX *g, int i, int j, bool *found){

    if(i == j){
        *found = true;
        return;
    }

    g[i].flag = 1;
    NODE *p = g[i].start;

    while(p){
        if(g[p->adj].flag == 0) deepAgain(g, p->adj, j, found);
        
        if(*found) return;

        p = p->next;
    }
    g[i].flag = 2;
}

VERTEX *mToList(int v, int m[v][v]){
    //cria um grafo lista de tamanho V (mesmo da matriz)
    VERTEX * answ = (VERTEX *) malloc((v+1)*sizeof(VERTEX));
    initialize(answ, v);

    int i, j;
    for(i = 1; i <= v; i++){
        for(j = 1; j <= v; j++){
            //percorre a matriz, quando acha arestas as cria no grafo VERTEX g
            if(m[i][j] == 1){
                NODE * new = (NODE*) malloc(sizeof(NODE));
                new -> adj = j;
                new -> next = answ[i].start;
                answ[i].start = new;
            }
        //answ[i].start = new; (acho que nada a ver)
        }
    }
    return answ;   
}

NODE * VERTICESRADIUS(VERTEX *g, int i, int n){
    NODE *answ = NULL;
    resetFlags(g, n); 
    //continuo amanhã (hj só q sem ser de madrugada)
}