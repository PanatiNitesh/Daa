#include <stdio.h>
#define MAX 10
#define INF 999

int a[MAX][MAX], d[MAX], n;

// Function to extract the vertex with the minimum distance
int Extract_Min(int S[]) {
    int i, j = -1, min = INF;
    for (i = 1; i <= n; i++) {
        if ((d[i] < min) && (!S[i])) {
            min = d[i];
            j = i;
        }
    }
    return j;
}

// Dijkstra's Algorithm
void Dijkstras(int s) {
    int S[MAX] = {0};
    int u, v;

    for (int i = 1; i <= n; i++) {
        d[i] = a[s][i]; // initialize distance
    }
    S[s] = 1;
    d[s] = 0;

    for (int count = 2; count <= n; count++) {
        u = Extract_Min(S);
        if (u == -1) break; // No reachable vertex
        S[u] = 1;

        for (v = 1; v <= n; v++) {
            if (!S[v] && a[u][v] != INF && d[u] + a[u][v] < d[v]) {
                d[v] = d[u] + a[u][v];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", s);
    for (int i = 1; i <= n; i++) {
        if (i != s) {
            if (d[i] == INF)
                printf("%d: Unreachable\n", i);
            else
                printf("%d: %d\n", i, d[i]);
        }
    }
}

// Main function
int main() {
    int s;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (999 for no direct edge):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    Dijkstras(s);

    return 0;
}
