//marcos
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


int main(){
    int v;
    printf("Matrix size: ");
    scanf("%d", &v);

    int m[v][v];
    initialize(v, m);

    int v1, v2;

    int ans = -1;
    while(ans!=0){
        printf("1 - Insert edge \n");
        printf("2 - Delete edge \n");
        printf("3 - Print Matrix Graph \n");
        printf("4 - Print entry level \n");
        printf("5 - Print exit level \n");
        printf("0 - Exit \n \n");
        scanf("%d", &ans);

        switch (ans)
        {
        case 1:
            printf("Insert edge at (line): ");
            scanf("%d", &v1);
            printf("...and (column): ");
            scanf("%d", &v2);
            insertEdge(v, m, v1, v2);
            break;

        case 2:
            printf("Delete edge at (line): ");
            scanf("%d", &v1);
            printf("...and (column): ");
            scanf("%d", &v2);
            deleteEdge(v, m, v1, v2);
            break;

        case 3: 
            printMatrix(v, m);
            break;
        
        case 4:
            printf("Determine v1 (line): ");
            scanf("%d", &v1);
            printf("%d\n\n", entryLevel(v, m, v1));
            break;

        case 5:
            printf("Determine v1 (line): ");
            scanf("%d", &v1);
            printf("%d\n\n", exitLevel(v, m, v1));
            break;

        default:
            break;
        }
    }


    return 0;
}