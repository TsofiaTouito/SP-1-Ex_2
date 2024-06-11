#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my_mat.h"

int shortestPath(int mat[SIZE][SIZE], int size, int i, int j);

void getMatrixValues(int mat[SIZE][SIZE], int size){

 for(int i = 0 ; i < size ; i++){
    for(int j = 0 ; j < size ; j++){
        scanf("%d", &mat[i][j]);
    }
 }
}


int isPath(int mat[SIZE][SIZE], int size, int i, int j){
  int dist = shortestPath(mat, size, i, j);
  return (dist = -1) ? FALSE : TRUE;
}


int shortestPath(int mat[SIZE][SIZE], int size, int i, int j){

//define a distance matrix
int dist[SIZE][SIZE] = {0}; 

for(int i = 0; i<size ; i++){
  for(int j = 0 ; j<size ; j++){

     if(mat[i][j] != 0){ 
        dist[i][j] = mat[i][j];
     }
     else{
        dist[i][j] = INFINITY;
     }
  }
}


for(int i = 0; i<size ; i++){
  for(int j = 0 ; j<size ; j++){
    for(int k = 0 ; k<size ; k++){
        //check 3 cases of basic conditions for existing path
        //dist[i][i] = 0, non-directed graph
        if( i!=j && dist[j][i] != INFINITY && dist[i][k] != INFINITY){
            if(dist[i][j] > dist[i][k] + dist[k][j]){
                dist[i][j] = dist[i][k] + dist[k][j];
             }
         }
    }
  }
}

//if there is existing path
if(dist[i][j] != INFINITY && dist[i][j] != 0)
    {
        return dist[i][j];
    }

return -1;
}


int max(int a, int b){
    return (a > b) ? a : b ;
}




int knapsack( int weights[MAX_ITEM], int values[MAX_ITEM], int selected_bool[MAX_ITEM]){

int dp[MAX_ITEM+1][MAX_WEIGHT+1] = {0};

for(int i = 1; i<MAX_ITEM ; i++){
    for(int j = 1; j<MAX_ITEM ; j++){

        if(weights[i-1]<=j){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j - weights[i-1]]+values[i-1] );
        }

        dp[i][j] = 0;

    }
}

//find the maximum value achievable, and the corresponding weight
int max = 0;
for(int i = 0 ; i < MAX_WEIGHT ; i++){

    if(dp[MAX_ITEM][i] > dp[MAX_ITEM][max]){
        max = i ;
    }
}

//find the chosen items
for(int j = MAX_ITEM; j > 0 ; j--){

    if(dp[j][max] != dp[j-1][max]){
        selected_bool[j-1] = 1;
        max-=weights[j-1];
    }
    else{
        selected_bool[j-1] = 0;
    }
}

return dp[MAX_ITEM][MAX_WEIGHT];

}

