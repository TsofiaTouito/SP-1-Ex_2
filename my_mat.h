#ifndef MY_MAT_H
#define MY_MAT_H

#define SIZE 10
#define TRUE 1
#define FALSE 0
#define INFINITY 2147483647 // The max number of int
#define MAX_ITEM 5
#define MAX_WEIGHT 20
#define MAX_S_LEN 20

// This functions is getting the values for the matrix from the user
// Getting a pointer to the start of the matrix, and int valuse for the size of it
void getMatrixValues(int[SIZE][SIZE], int);

int isPath(int[SIZE][SIZE], int,int, int);

int shortestPath(int[SIZE][SIZE], int, int, int);

int knapsack( int[MAX_ITEM], int[MAX_ITEM], int[MAX_ITEM]);

#endif
