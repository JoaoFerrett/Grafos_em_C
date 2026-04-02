#include "GLista.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    
    int v = 0;
    VERTEX *g = NULL;
    VERTEX *gt = NULL;

    int ans = -1;
    while(ans!=0){
        printf("Insert a number for play with list of adjacencies Graph: \n\n");
        printf("1 - Create a Graph \n");
        printf("2 - Create an Edge \n");
        printf("3 - Delete an Edge \n");
        printf("4 - Print your Graph \n");
        printf("5 - Create the transpose Graph \n");
        printf("6 - Print the transpose Graph \n");
        printf("0 - Exit \n\n");

        if(scanf("%d", &ans) != 1){
        printf("Invalid input! Please enter a number.\n");
        while (getchar() != '\n');
        continue;
        }

        switch (ans)
        {
        case 1:
        if(g != NULL){
            free(g);
        }
            printf("Enter the number of vertices in the Graph (0 - n): \n");
            scanf("%d", &v);
            g = malloc(v * sizeof(VERTEX));
            initialize(g, v);
            printf("The Graph was created successfully! \n\n");
            break;

        case 2:
            if(g == NULL){
                printf("You have to create a Graph first! \n\n");
                break;
            }
            int v1, v2;
            printf("The edge goes from (node number): \n");
            scanf("%d", &v1);
            printf("Goes to (node number): \n");
            scanf("%d", &v2);
            if(v1 < 0 || v1 >= v || v2 < 0 || v2 >= v){
                printf("You have to choice an existent Vertex! (0 to %d)\n\n", v-1);
                break;
            }
            addEdge(g, v1, v2);
            printf("The Edge was created successfully! \n\n");
            break;
        
        case 3:
            if(g == NULL){
                printf("You have to create a Graph first! \n\n");
                break;
            }
            int n1, n2;
            printf("Node from edge starts: \n");
            scanf("%d", &n1);
            printf("Node from it ends \n");
            scanf("%d", &n2);
            deleteEdge(g, n1, n2);

            if(deleteEdge(g, n1, n2)){
                printf("The Edge was deleted successfully! \n");
            }else
                printf("This Edge doesn't exists \n");
            break;
        
        case 4:
            if(g == NULL){
                printf("You have to create a Graph first! \n\n");
                break;
            }
            printf("Your Graph here: \n\n");
            printG(g, v); 
            break;

        case 5:
            if(g == NULL){
                printf("You have to create a Graph first! \n\n");
                break;
            }
            gt = transpose(g, v);
            printf("The transpose Graph was succesfully created! \n");
            break;

        case 6: 
            if(g == NULL){
                printf("You have to create a Graph first! \n\n");
                break;
            }if(gt == NULL){
                printf("You have to create a Transpose Graph first! \n\n");
                break;
            }
            printf("Your transpose Graph here: \n\n");
            printG(gt, v);
            break;
            
        
        case 0:
            printf("See you soon... \n\n");
            break;
        
        default:
            printf("Invalid number/option! \n");
            break;
        }
    }

}