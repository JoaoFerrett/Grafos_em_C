#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct s{
    int adj;
    struct s *next;
} NODE;

typedef struct{
    NODE *start;
    int flag;
} VERTEX;

void initialize(VERTEX *g, int v);
bool edgeExists(VERTEX *g, int v1, int v2);
bool addEdge(VERTEX *g, int v1, int v2);
bool deleteEdge(VERTEX *g, int v1, int v2);
void printG(VERTEX *g, int v);
bool verifySubG(VERTEX *g, VERTEX *gz, int v);

VERTEX *transpose(VERTEX *g, int v);

void deep(VERTEX *g, int i);
void deepAgain(VERTEX *g, int i, int j, bool *found);

VERTEX *mToList(int v, int m[v][v]);

#endif