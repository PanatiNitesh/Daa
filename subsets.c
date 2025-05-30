//subsets program

#include <stdio.h>

#define MAX 10

int S[MAX], soln[MAX], d;

void SumofSub(int i, int weight, int total);
int promising(int i, int weight, int total);

int main() {
    int n, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the set in increasing order:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &S[i]);
        sum += S[i];
    }

    printf("Enter the required subset sum (d): ");
    scanf("%d", &d);

    if (sum < d || S[1] > d)
        printf("No Subset possible\n");
    else
        SumofSub(0, 0, sum);

    return 0;
}

void SumofSub(int i, int weight, int total) {
    if (promising(i, weight, total)) {
        if (weight == d) {
            printf("Subset found: ");
            for (int j = 1; j <= i; j++)
                if (soln[j])
                    printf("%d ", S[j]);
            printf("\n");
        } else {
            soln[i + 1] = 1;
            SumofSub(i + 1, weight + S[i + 1], total - S[i + 1]);
            soln[i + 1] = 0;
            SumofSub(i + 1, weight, total - S[i + 1]);
        }
    }
}

int promising(int i, int weight, int total) {
    return (weight + total >= d) && (weight == d || weight + S[i + 1] <= d);
}
