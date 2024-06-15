#ifndef MERGE_SORT_H
#define MERGE_SORT_H

void mergeSort(int arr[], int l, int r, int *swapCounter);

#endif // MERGE_SORT_H


#include <stdio.h>

// Function to merge two halves
void merge(int arr[], int l, int m, int r, int *swapCounter) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            *swapCounter += (n1 - i); // Increase inversion count
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void mergeSort(int arr[], int l, int r, int *swapCounter) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, l, m, swapCounter);
        mergeSort(arr, m + 1, r, swapCounter);

        // Merge the sorted halves
        merge(arr, l, m, r, swapCounter);
    }
}

void mergeSortWrapper(int arr[], int n, int *swapCounter) {
    *swapCounter = 0;
    mergeSort(arr, 0, n - 1, swapCounter);
}
