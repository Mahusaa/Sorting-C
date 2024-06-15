#include "time_measure.c"
#include "merge_sort.c"
#include <stdlib.h>

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000 + 1; // Generate random numbers between 1 and 10000
    }
}

int main() {
    srand(time(NULL)); 
    
    int n10 = 10;
    int n100 = 100;
    int n1000 = 1000;
    int n10000 = 10000;
    
    int arr10[n10];
    int arr100[n100];
    int arr1000[n1000];
    int arr10000[n10000];
    
    generateRandomArray(arr10, n10);
    generateRandomArray(arr100, n100);
    generateRandomArray(arr1000, n1000);
    generateRandomArray(arr10000, n10000);
    
    int swapCounter;

    printf("Testing array with 10 elements:");
    measureSortTime(mergeSortWrapper, arr10, n10, &swapCounter);
    
    printf("Testing array with 100 elements:");
    measureSortTime(mergeSortWrapper, arr100, n100, &swapCounter);
    
    printf("Testing array with 1000 elements:");
    measureSortTime(mergeSortWrapper, arr1000, n1000, &swapCounter);
    
    printf("Testing array with 10000 elements:");
    measureSortTime(mergeSortWrapper, arr10000, n10000, &swapCounter);

    return 0;
}
