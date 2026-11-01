#include <stdio.h>
#include <stdlib.h>
#define MAX 100
// Structure to represent an edge
struct Edge
{
    int src, dest, weight;
};
// Structure for Union-Find subsets
struct Subset
{
    int parent;
    int rank;
};
// Find function with path compression
int find(struct Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
// Union by rank
void Union(struct Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare edges for qsort (increasing order of weight)
int compare(const void *a, const void *b)
{
    struct Edge *a1 = (struct Edge *)a;
    struct Edge *b1 = (struct Edge *)b;
    return (a1->weight > b1->weight) - (a1->weight < b1->weight);
}
// Kruskal’s MST Algorithm
void KruskalMST(struct Edge edges[], int V, int E)
{
    struct Edge result[MAX]; // Store MST edges
    int e = 0;               // Count of edges in result
    int i = 0;               // Index for sorted edges
    // Step 1: Sort all edges by weight
    qsort(edges, E, sizeof(edges[0]), compare);
    // Allocate memory for Union-Find subsets
    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    // Step 2: Pick edges one by one
    while (e < V - 1 && i < E)
    {
        struct Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        // If including this edge doesn’t form a cycle
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    // Print the result MST
    printf("\nEdges in the Minimum Spanning Tree:\n");

    int minCost = 0;
    for (i = 0; i < e; i++)
    {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        minCost += result[i].weight;
    }
    printf("Minimum Cost of Spanning Tree = %d\n", minCost);
    free(subsets);
}
int main()
{
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    struct Edge edges[MAX];
    printf("Enter edges (src dest weight) [use 0-based vertex indices]:\n");
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }
    KruskalMST(edges, V, E);
    return 0;
}