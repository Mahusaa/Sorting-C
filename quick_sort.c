#ifndef QUICKSORT_H
#define QUICKSORT_H

void quickSort(int arr[], int left, int right, int *swapCounter);

#endif 

#include "utils.c"
#include <stdlib.h>

// Function to implement quicksort
int partition(int arr[], int left, int right, int *swapCounter) {
    int pivotIndex = left;
    int pivotValue = arr[pivotIndex];
    int storeIndex = pivotIndex + 1;

    for (int i = pivotIndex + 1; i <= right; i++) {
        // Include 50% chance for equal elements
        if (arr[i] < pivotValue || (arr[i] == pivotValue && rand() % 2 == 0)) {
            swap(&arr[i], &arr[storeIndex]);
            ++storeIndex;
            ++(*swapCounter);
        }
    }

    swap(&arr[pivotIndex], &arr[storeIndex - 1]);
    ++(*swapCounter);
    return storeIndex - 1;
}

void quickSort(int arr[], int left, int right, int *swapCounter) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right, swapCounter);
        quickSort(arr, left, pivotIndex - 1, swapCounter);
        quickSort(arr, pivotIndex + 1, right, swapCounter);
    }
}

void quickSortWrapper(int arr[], int n, int *swapCounter) {
    *swapCounter = 0;
    quickSort(arr, 0, n - 1, swapCounter);
}