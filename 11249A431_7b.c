#include <stdio.h>
#include <stdlib.h>

#define V 4   // Number of vertices
#define E 5   // Number of edges

// Comparator for qsort
int comparator(const void *a, const void *b)
{
    int *p1 = (int *)a;
    int *p2 = (int *)b;
    return p1[2] - p2[2];
}

// Initialize sets
void makeSet(int parent[], int rank[])
{
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find with path compression
int findParent(int parent[], int component)
{
    if (parent[component] != component)
        parent[component] = findParent(parent, parent[component]);
    return parent[component];
}

// Union by rank
void unionSet(int u, int v, int parent[], int rank[])
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

// Kruskal's Algorithm
int kruskalAlgo(int edge[E][3])
{
    qsort(edge, E, sizeof(edge[0]), comparator);

    int parent[V];
    int rank[V];
    makeSet(parent, rank);

    int minCost = 0;

    for (int i = 0; i < E; i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];

        if (findParent(parent, u) != findParent(parent, v)) {
            unionSet(u, v, parent, rank);
            minCost += wt;
        }
    }

    return minCost;
}

// Driver code
int main()
{
    int edge[E][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    printf("Minimum Cost of MST: %d\n", kruskalAlgo(edge));

    return 0;
}
