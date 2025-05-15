#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int i, j, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];

int find(int i);
void uni(int i, int j);

void main() {
    clrscr(); // Clears screen (optional, remove if unsupported)

    printf("\n\n\tImplementation of Kruskal's algorithm\n\n");

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999; // Replace 0 with a large number to represent no edge
        }
    }

    printf("\nThe edges of Minimum Cost Spanning Tree are:\n\n");
    while (ne < n) {
        min = 999;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        int a = find(u);
        int b = find(v);

        if (a != b) {
            uni(a, b);
            printf("%d edge (%d,%d) = %d\n", ne++, u, v, min);
            mincost += min;
        }

        cost[u][v] = cost[v][u] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);
    getch();
}

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

void uni(int i, int j) {
    parent[j] = i;
}
