#include <stdio.h>
#include <stdlib.h>
#define N 5
/*you need to design a scheduler that will schedule a set of tasks,
a number of the tasks need to wait for some other tasks to complete prior to running themselves. What algorithm 
could be used to design the scheduler and how would you implement it*/
int removevertex(int *a)
{
}
void main()
{

    int graph[N][N] = {{0, 0, 1, 0, 0},
                       {0, 0, 1, 0, 0},
                       {0, 0, 0, 1, 1},
                       {0, 0, 0, 0, 1},
                       {0, 0, 0, 0, 0}};

    int sorted_vertices[5], set_edges[6];
    int j, k, i;
    for (i = 0; i < 6; i++)
    {
        set_edges[i] = 0;
    }

    //set_edges[5] checks whether the set is empty or not
    for (j = 0; j < N; j++)
    {
        for (k = 0; k < N; k++)
        {
            if (graph[k][j] == 1)
                break;
        }
        if (k == N)
        {
            set_edges[j] = 1;
            set_edges[5] = 1;
        }
    }
    while (set_edges[5])
    {
    }
}