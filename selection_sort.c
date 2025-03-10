#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void selection_sort(int arr[], int n) {
    int i, j, min_index;
    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main() {
    int i, n;
    printf("\nEnter n: ");
    scanf("%d", &n);
    
    int array[n];
    srand((unsigned) time(NULL));
    
    for (i = 0; i < n; i++) {
        array[i] = rand() % 100;
    }
    
    clock_t start, stop;
    double duration;

    start = clock();
    selection_sort(array, n);
    stop = clock();

    duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("\nSorting Time: %f seconds\n", duration);

    return 0;
}
