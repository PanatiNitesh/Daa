//topo sort

#include <stdio.h>

#define MAX 10

int graph[MAX][MAX], n, visited[MAX], result[MAX];

void readGraph() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;
}

int indegree(int node) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (graph[i][node] == 1)
            count++;
    return count;
}

void topologicalSort() {
    int index = 0;

    for (int step = 0; step < n; step++) {
        for (int i = 0; i < n; i++) {
            if (!visited[i] && indegree(i) == 0) {
                visited[i] = 1;
                result[index++] = i + 1; // 1-based output

                for (int j = 0; j < n; j++)
                    graph[i][j] = 0; // remove edges from i
                break;
            }
        }
    }

    printf("Topological Order: ");
    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);
    printf("\n");
}

int main() {
    readGraph();
    topologicalSort();
    return 0;
}
