//n queens

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int count = 0;

int Place(int x[], int k) {
    for (int i = 0; i < k; i++) {
        if (x[i] == x[k] || abs(x[i] - x[k]) == abs(i - k))
            return 0;
    }
    return 1;
}

void Display(int x[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (x[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

void nQueens(int n) {
    int x[MAX], k = 0;
    for (int i = 0; i < MAX; i++) x[i] = -1;

    while (k >= 0) {
        x[k]++;
        while (x[k] < n && !Place(x, k))
            x[k]++;
        if (x[k] < n) {
            if (k == n - 1) {
                count++;
                Display(x, n);
            } else {
                k++;
                x[k] = -1;
            }
        } else {
            k--;
        }
    }
}

int main() {
    int n;
    printf("Enter number of queens: ");
    scanf("%d", &n);

    nQueens(n);
    printf("Total solutions: %d\n", count);
    return 0;
}
