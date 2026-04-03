#ifndef MGRAPH_H
#define MGRAPH_H

#include <stdlib.h>
#include <stdbool.h>

void initialize(int v, int m[v][v]);
void insertEdge(int v, int m[v][v], int v1, int v2);
void deleteEdge(int v, int m[v][v], int v1, int v2);
bool edgeExists(int v, int m[v][v], int v1, int v2);
int entryLevel(int v, int m[v][v], int v1);
int exitLevel(int v, int m[v][v], int v1);
void printMatrix(int v, int m[v][v]);
void deep(int v, int m[v][v], int flag[v], int i);
 

#endif
