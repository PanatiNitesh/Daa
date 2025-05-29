//knapsack 0/1

#include <stdio.h>

#define MAX 20

int V[MAX][MAX];

int knapsack(int profit[], int weight[], int n, int capacity) {
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                V[i][w] = 0;
            else if (weight[i] <= w)
                V[i][w] = (profit[i] + V[i-1][w - weight[i]] > V[i-1][w]) ?
                           profit[i] + V[i-1][w - weight[i]] : V[i-1][w];
            else
                V[i][w] = V[i-1][w];
        }
    }

    return V[n][capacity];
}

int main() {
    int profit[MAX], weight[MAX], n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &weight[i]);

    printf("Enter profits:\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &profit[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    int maxProfit = knapsack(profit, weight, n, capacity);
    printf("Maximum profit: %d\n", maxProfit);

    return 0;
}
