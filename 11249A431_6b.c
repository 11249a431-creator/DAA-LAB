#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 6
#define INF INT_MAX

int graph[MAX_VERTICES][MAX_VERTICES] = {
    {0, 10, 0, 15, 0, 0},
    {0, 0, 0, 5, 10, 0},
    {0, 0, 0, 0, 0, 10},
    {0, 0, 0, 0, 0, 5},
    {0, 0, 0, 0, 0, 10},
    {0, 0, 0, 0, 0, 0}
};

void bellman_ford(int source) {
    int distance[MAX_VERTICES];

    // Initialize distances
    for (int i = 0; i < MAX_VERTICES; i++) {
        distance[i] = INF;
    }
    distance[source] = 0;

    // Relax edges (V-1 times)
    for (int i = 0; i < MAX_VERTICES - 1; i++) {
        for (int u = 0; u < MAX_VERTICES; u++) {
            for (int v = 0; v < MAX_VERTICES; v++) {
                if (graph[u][v] != 0 &&
                    distance[u] != INF &&
                    distance[u] + graph[u][v] < distance[v]) {

                    distance[v] = distance[u] + graph[u][v];
                }
            }
        }
    }

    // Check for negative weight cycles
    for (int u = 0; u < MAX_VERTICES; u++) {
        for (int v = 0; v < MAX_VERTICES; v++) {
            if (graph[u][v] != 0 &&
                distance[u] != INF &&
                distance[u] + graph[u][v] < distance[v]) {

                printf("Graph contains negative weight cycle\n");
                return;
            }
        }
    }

    // Print results
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (distance[i] == INF)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, distance[i]);
    }
}

int main() {
    bellman_ford(0);
    return 0;
}
