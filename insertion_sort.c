#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

void insertionSort(int arr[], int n, int *swapCounter);

#endif // INSERTION_SORT_H

#include "utils.c"

// Function to implement insertion sort
void insertionSort(int arr[], int n, int *swapCounter) {
    *swapCounter = 0;

    // Mark first element as sorted
    for (int i = 1; i < n; ++i) {
        // 'Extract' the element X
        int key = arr[i];
        int j = i - 1;

        // For j = lastSortedIndex down to 0
        while (j >= 0 && arr[j] > key) {
            // Move sorted element to the right by 1
            arr[j + 1] = arr[j];
            j--;
            ++(*swapCounter);
        }

        // Insert X here
        arr[j + 1] = key;
    }
}
