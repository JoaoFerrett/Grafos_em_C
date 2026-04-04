#include "GMatriz.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

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

        if(scanf("%d", &ans) != 1){
        printf("Invalid input! Please enter a number.\n\n");
        while (getchar() != '\n');
        continue;
        }

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