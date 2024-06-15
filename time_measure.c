#ifndef TIME_MEASURE_H
#define TIME_MEASURE_H

void measureSortTime(void (*sortFunc)(int[], int, int*), int arr[], int n, int *swapCounter);

#endif // TIME_MEASURE_H

#include <time.h>
#include <stdio.h>

void measureSortTime(void (*sortFunc)(int[], int, int*), int arr[], int n, int *swapCounter) {
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();
    sortFunc(arr, n, swapCounter);
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("\nTotal swaps: %d\n", *swapCounter);
    printf("Time taken to sort: %f seconds\n\n", cpu_time_used);
}
