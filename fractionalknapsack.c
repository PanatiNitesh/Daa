//fractional knapsack

#include <stdio.h>

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    float weight[50], profit[50], ratio[50];
    float capacity, totalValue = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights and profits:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight and Profit: ", i + 1);
        scanf("%f %f", &weight[i], &profit[i]);
        ratio[i] = profit[i] / weight[i];
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);


    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(&ratio[i], &ratio[j]);
                swap(&weight[i], &weight[j]);
                swap(&profit[i], &profit[j]);
            }
        }
    }

    for (int i = 0; i < n && capacity > 0; i++) {
        if (weight[i] <= capacity) {
            totalValue += profit[i];
            capacity -= weight[i];
        } else {
            totalValue += ratio[i] * capacity;
            break;
        }
    }

    printf("Maximum value in knapsack = %.2f\n", totalValue);
    return 0;
}
