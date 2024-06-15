#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <stdbool.h>

void bubbleSort(int arr[], int n, int *swapCounter);

#endif // BUBBLE_SORT_H

#include "utils.c"

// Function to implement bubble sort
void bubbleSort(int arr[], int n, int *swapCounter) {
    bool swapped;
    int i;
    *swapCounter = 0;
    
    do {
        swapped = false;
        
        for (i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                swapped = true;
                ++(*swapCounter);
            }
        }
        --n;
        
    } while (swapped);
}
