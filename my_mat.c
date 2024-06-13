#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"


int fw(int mat[SIZE][SIZE], int size, int i, int j);
void getMatrixValues(int mat[SIZE][SIZE], int size);

void getMatrixValues(int mat[SIZE][SIZE], int size) {
    for(int i = 0 ; i < size ; i++) {
        for(int j = 0 ; j < size ; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

int isPath(int mat[SIZE][SIZE], int size, int i, int j) {
    int dist = shortestPath(mat, size, i, j);
    return (dist == -1) ? FALSE : TRUE; 
}


int shortestPath(int mat[SIZE][SIZE], int size, int i, int j) {

    return fw(mat,size,i,j);
}


int fw(int mat[SIZE][SIZE], int size, int i, int j) {
    int dist[SIZE][SIZE] = {0};

    // Initialize the distance matrix
    for(int x = 0; x < size; x++) {
        for(int y = 0; y < size; y++) {
            if(x == y)
            {
                continue;
            }
            if(mat[x][y] != 0) {
                dist[x][y] = mat[x][y];
            } else {
                dist[x][y] = INFINITY;
            }
        }
    }

    // Floyd-Warshall algorithm to find shortest paths
    for(int k = 0; k < size; k++) {
        for(int x = 0; x < size; x++) {
            for(int y = 0; y < size; y++) {
                if(x != y && dist[x][k] != INFINITY && dist[k][y] != INFINITY) {
                    if(dist[x][y] > dist[x][k] + dist[k][y]) {
                        dist[x][y] = dist[x][k] + dist[k][y];
                    }
                }
            }
        }
    }

    // Return the shortest path from i to j
    if(dist[i][j] != INFINITY && dist[i][j] != 0) {
        return dist[i][j];
    }
    return -1;
}


int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int weights[MAX_ITEM], int values[MAX_ITEM], int selected_bool[MAX_ITEM]) {
    int dp[MAX_ITEM+1][MAX_WEIGHT+1] = {0};

    // Fill the dp array
    for (int i = 1; i <= MAX_ITEM; i++) {
        for (int j = 0; j <= MAX_WEIGHT; j++) {
            if (weights[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - weights[i-1]] + values[i-1]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // Find the maximum value achievable and the corresponding weight
    int max = 0;
    for (int i = 0; i <= MAX_WEIGHT; i++) {
        if (dp[MAX_ITEM][i] > dp[MAX_ITEM][max]) {
            max = i;
        }
    }

    // Find the chosen items
    for (int j = MAX_ITEM; j > 0; j--) {
        if (dp[j][max] != dp[j-1][max]) {
            selected_bool[j-1] = 1;
            max -= weights[j-1];
        } else {
            selected_bool[j-1] = 0;
        }
    }

    return dp[MAX_ITEM][MAX_WEIGHT];
}



