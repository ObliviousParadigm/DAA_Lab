// Header file for travelling salesman problem
#include<stdlib.h>

// Get the next permutation in lexicographical order
// Returns 0 if there is no permutation which lexicographically bigger
// Implemented in tsp_sampletest.c and tsp_tests.c
// Not to be implemented as a part of lab session
int get_next_permutation(int *permutation, int n);

//Finds a solution for the traveling salesman problem
//Returns the cost of a min-cost Hamiltonian circuit of the given
//directed complete graph with n vertices in the form a cost matrix.
int tsp(int n, int graph[][n])
{
    int a[n - 1];
    for (int j = 1; j < n; j++)
    {
        a[j - 1] = j;
    }
    int min_cost = 9999;

    do
    {
        int cost = 0;
        int k = 0;
        for (int i = 0; i < n - 1; i++)
        {
            cost += graph[k][a[i]];
            k = a[i];
        }
        cost += graph[k][0];
        if (cost < min_cost)
        {
            min_cost = cost;
        }
    } while (get_next_permutation(a, n - 1));
    return min_cost;
}

// Returns an array of size n,
// starting at city_0 (that is the first node)
// traversing the path with min-cost
// Note: Return the path which is lexicographically smaller in case two paths have the same cost
int *printPath(int n, int graph[][n])
{
    int a[n - 1];
    for (int j = 1; j < n; j++)
    {
        a[j - 1] = j;
    }
    int min_cost = 9999;

    int *temp;
    temp = (int *)malloc(n * sizeof(int));
    do
    {
        int cost = 0;
        int k = 0;
        for (int i = 0; i < n - 1; i++)
        {
            cost += graph[k][a[i]];
            k = a[i];
        }
        cost += graph[k][0];
        if (cost < min_cost)
        {
            min_cost = cost;
            temp[0] = 0;
            for (int j = 1; j < n; j++)
            {
                temp[j] = a[j - 1];
            }
        }
    } while (get_next_permutation(a, n - 1));
    return temp;
}

// Given a permutation of path - P[],
// Return the cost from the starting city through the path and back
// P[0] -> P[1] -> ... -> P[n-1] -> P[0]
int getCost(int n, int graph[][n], int *P)
{
    int k = P[0];
    int cost = 0;
    for (int j = 1; j < n; j++)
    {
        cost += graph[k][P[j]];
        k = P[j];
    }
    cost += graph[k][P[0]];
    return cost;
}
