#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

void selectionSort(int arr[], int n, int *swapCounter);

#endif // SELECTION_SORT_H

#include "utils.c"

void selectionSort(int arr[], int n, int *swapCounter) {
    int i, j, minIdx;
    *swapCounter = 0;
    
    // Repeat (n - 1) times
    for (i = 0; i < n - 1; ++i) {
        // Set the first unsorted element as the minimum
        minIdx = i;
        
        // For each of the unsorted elements
        for (j = i + 1; j < n; ++j) {
            // If element < currentMinimum, set element as new minimum
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        
        // Swap minimum with first unsorted position
        if (minIdx != i) {
            swap(&arr[i], &arr[minIdx]);
            ++(*swapCounter);
        }
    }
}
