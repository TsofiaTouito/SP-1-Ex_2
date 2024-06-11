#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"


int main()
{
    int graph[SIZE][SIZE] = {0};

    char userChoice;
    int i, j;

    scanf("%c", &userChoice);
    while (userChoice != 'D' && userChoice) // Exit the program
    {   
        if (userChoice == 'A') // Entering value to the graph that represented as a matrix
        {
            getMatrixValues(graph, SIZE);
        }
        else if (userChoice == 'B') // Finding a path from i to j in the graph
        {
            scanf("%d%d", &i, &j);
            printf("%s\n", isPath(graph, SIZE, i, j) ? "True" : "False");
        }
        else if (userChoice == 'C') // If there is a path fiding the shortest-path
        {
            scanf("%d%d", &i, &j);
            printf("%d\n", shortestPath(graph, SIZE, i, j));
        }
        scanf(" %c", &userChoice); // For entering another choise
    }


    return 0;
}
