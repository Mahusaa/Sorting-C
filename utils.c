#ifndef UTILS_H
#define UTILS_H

void swap(int *a, int *b);

#endif 

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
