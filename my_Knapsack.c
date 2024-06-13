#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"


int main(){

char items[MAX_ITEM][MAX_S_LEN];
int values[MAX_ITEM];
int weights[MAX_ITEM];
int selected_bool[MAX_ITEM];



for(int i = 0; i < MAX_ITEM ; i++){
    scanf("%s %d %d ", items[i], &values[i], &weights[i]);
}



printf("Maximum value: %d\n", knapsack(weights, values, selected_bool));

printf("Selected items:");
for(int i = 0 ; i < MAX_ITEM ; i++){
    if(selected_bool[i]){
       printf(" %s", items[i]);
    }
}


return 0;
}


