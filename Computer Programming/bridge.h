#ifndef BRIDGE_H_INCLUDED
#define BRIDGE_H_INCLUDED
#include <stdbool.h>

void test();
void createArray(int *a, int n);
void insertionSort(int *a, int n);
bool isSorted(int *a, int n);
int merge(int *a, int s1, int e1, int s2, int e2, int* m1, int* m2);
int mergeSort(int *a, int len);
int quicksort_r(int* a, int start, int end);
void printArray(int *a, int size);
int quicksort(int*a, int len);
void selectionSort(int *a, int size);
void swap(int a, int b);

#endif
 