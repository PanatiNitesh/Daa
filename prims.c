//prims algo

#include <stdio.h>

int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0}, min, mincost = 0, cost[10][10];

void main() {
    printf("\n\tImplementation of Prim's Algorithm\n");
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999; // Treat 0 as no edge
        }
    }

    visited[1] = 1; // Start from vertex 1

    printf("\nThe edges of Minimum Cost Spanning Tree are:\n");
    while (ne < n) {
        for (i = 1, min = 999; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                *if (cost[i][j] < min) {
                    if (visited[i] != 0 && visited[j] == 0) {
*                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        visited[v] = 1;
        printf("Edge %d: (%d -> %d) cost: %d\n", ne++, a, b, min);
        mincost += min;
        cost[a][b] = cost[b][a] = 999; // Mark edge as used
    }

    printf("\nMinimum cost = %d\n", mincost);
}
