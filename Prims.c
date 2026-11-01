#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// Function to find the vertex with the minimum weight
int minweight(int V, int weight[], bool visited[])
{
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && weight[v] < min)
        {
            min = weight[v];
            min_index = v;
        }
    }
    return min_index;
}
// Function to print the constructed MST and its total cost
void printMST(int V, int parent[], int **graph)
{
    int totalCost = 0;
    printf("\nMST for the graph:\n");
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d \n", parent[i], i,
               graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("Total cost of MST: %d\n", totalCost);
}

// Function to construct and print MST for a graph
void primMST(int V, int **graph)
{
    int *parent = (int *)malloc(V * sizeof(int));
    int *weight = (int *)malloc(V * sizeof(int));
    bool *visited = (bool *)malloc(V * sizeof(bool));
    // Initialize all weights as infinite and visited[] as false
    for (int i = 0; i < V; i++)
    {
        weight[i] = INT_MAX;
        visited[i] = false;
    }
    // Always include first vertex in MST
    weight[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minweight(V, weight, visited);
        visited[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !visited[v] && graph[u][v] < weight[v])
            {
                parent[v] = u;
                weight[v] = graph[u][v];
            }
        }
    }
    printMST(V, parent, graph);
    free(parent);
    free(weight);
    free(visited);
}
int main()
{
    int V;
    printf("Enter number of vertices: ");

    scanf("%d", &V);
    // Dynamically allocate adjacency matrix
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
    {
        graph[i] = (int *)malloc(V * sizeof(int));
    }
    printf("Enter the adjacency matrix (%d x %d):\n", V, V);
    printf("(Enter 0 if there is no edge between two vertices)\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    primMST(V, graph);
    // Free memory
    for (int i = 0; i < V; i++)
    {
        free(graph[i]);
    }
    free(graph);
    return 0;
}