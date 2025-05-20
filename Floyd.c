//
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

void Floyds(int D[10][10], int n) {
    int i, j, k;
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
}

int main() {
    int n, i, j, D[10][10];

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the weighted matrix (use 999 for infinity):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &D[i][j]);
        }
    }

    Floyds(D, n);

    printf("\nAll-pairs shortest paths matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (D[i][j] == 999)
                printf("INF\t");
            else
                printf("%d\t", D[i][j]);
        }
        printf("\n");
    }

    return 0;
}
