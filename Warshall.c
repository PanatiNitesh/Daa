
#include <stdio.h>
#define MAX 10

void warshall(int P[MAX][MAX], int n) {
    int i, j, k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                P[i][j] = P[i][j] || (P[i][k] && P[k][j]);
            }
        }
    }
}

int main() {
    int n, P[MAX][MAX], i, j;
    printf("Enter the number of vertices: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Invalid vertex count.\n");
        return 1;
    }

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &P[i][j]);
        }
    }

    warshall(P, n);

    printf("The transitive closure is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", P[i][j]);
        }
        printf("\n");
    }

    return 0;
}