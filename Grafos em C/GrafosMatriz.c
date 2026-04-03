#include "GMatriz.h"

#include <stdio.h>
#include <stdbool.h>


void initialize(int v, int m[v][v]){
    int i, j;
    
    for(i = 0; i < v; i++){
        for(j = 0; j < v; j++){
            m[i][j] = 0;
        }
    }

}

void insertEdge(int v, int m[v][v], int v1, int v2){
    m[v1][v2] = 1;
    m[v2][v1] = 1;
}

void deleteEdge(int v, int m[v][v], int v1, int v2){
    m[v1][v2] = 0;
    m[v2][v1] = 0;
    printf("Deleted edge... \n");
}

// inutil pq eu printo a matriz, oq é mt mais legal
bool edgeExists(int v, int m[v][v], int v1, int v2){
    if(m[v1][v2] == 1){
        return true;
    }
        else
        return false;
}

int entryLevel(int v, int m[v][v], int v1){
    int i, entryl = 0;
    for(i = 0; i < v; i++){
        entryl = entryl + m[i][v1];
    }
    return entryl;
}

int exitLevel(int v, int m[v][v], int v1){
    int i, exitl = 0;
    for(i = 0; i < v; i++){
        exitl = exitl + m[v1][i];
    }
    return exitl;
}

//Como é grafo não dirigido - no momento desse comentário, entry e exit Level devem ser iguais (eu acho)


void printMatrix(int v, int m[v][v]) {
    int i, j;

    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void deep(int v, int m[v][v], int flag[v], int i){
    flag[i] = 1;
    int j;
    for(j = 0; j < v; j++){
        if(m[i][j] == 1 && flag[j] == 0){
            deep(v, m, flag, j);
        }
    }
    flag[i] == 2;
}