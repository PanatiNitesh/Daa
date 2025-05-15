#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function to perform selection sort on an array
void selection_sort(int arr[], int n) {
    int i, j, min_index;
    // Traverse through all array elements except the last one
    for (i = 0; i < n - 1; i++) {
        min_index = i; // Assume the current position is the minimum
        // Find the minimum element in the unsorted part of the array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j; // Update min_index if a smaller element is found
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main() {
    int i, n;

    // Input the size of the array
    printf("\nEnter n: ");
    scanf("%d", &n);

    int array[n];  // Declare array of size n

    // Seed the random number generator with current time
    srand((unsigned) time(NULL));

    // Fill the array with random integers between 0 and 99
    for (i = 0; i < n; i++) {
        array[i] = rand() % 100;
    }

    clock_t start, stop;
    double duration;

    // Record start time before sorting
    start = clock();

    // Call selection sort function
    selection_sort(array, n);

    // Record stop time after sorting
    stop = clock();

    // Calculate duration in seconds
    duration = ((double)(stop - start)) / CLOCKS_PER_SEC;

    // Print the time taken to sort the array
    printf("\nSorting Time: %f seconds\n", duration);

    return 0;
}
