//Dijkstra’s

#include <stdio.h>
#define MAX 10
#define INF 9999

int a[MAX][MAX], d[MAX], visited[MAX], n;

void Dijkstra(int start) {
    int i, j, u, min;

    for (i = 1; i <= n; i++) {
        d[i] = a[start][i];      // Initialize distances from start
        visited[i] = 0;          // Mark all nodes as unvisited
    }

    d[start] = 0;                // Distance to itself is 0
    visited[start] = 1;          // Mark starting node as visited

    for (i = 1; i < n; i++) {
        min = INF;
        u = -1;

        
        for (j = 1; j <= n; j++) {
            if (!visited[j] && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        visited[u] = 1;

        // Update distances to adjacent vertices
        for (j = 1; j <= n; j++) {
            if (!visited[j] && d[u] + a[u][j] < d[j]) {
                d[j] = d[u] + a[u][j];
            }
        }
    }

    // Print shortest distances
    printf("\nShortest distances from vertex %d:\n", start);
    for (i = 1; i <= n; i++) {
        if (i != start)
            printf("To vertex %d: %d\n", i, d[i]);
    }
}

void main() {
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0 && i != j)
                a[i][j] = INF;  // No edge is treated as INF
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    Dijkstra(start);
}
