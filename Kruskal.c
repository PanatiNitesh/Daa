//Kruskal’s Algorithm

#include <stdio.h>
#include <stdlib.h>

int i, j, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];

// Function to find the root of an element
int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

// Function to perform union of two subsets
void uni(int i, int j) {
    parent[j] = i;
}

void main() {
    printf("\n\n\tImplementation of Kruskal's algorithm\n\n");
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999; // Treat 0 as no edge
        }
    }

    printf("\nThe edges of Minimum Cost Spanning Tree are:\n\n");
    while (ne < n) {
        for (i = 1, min = 999; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (u != v) {
            uni(u, v);
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999; // Remove selected edge
    }

    printf("\nMinimum cost = %d\n", mincost);
}
