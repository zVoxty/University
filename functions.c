#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"
#include <time.h>

void createArray(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("Insert a[%d]: ",i + 1 );
        scanf("%d", &a[i]);
    }
}

void printArray(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int *a, int n, int m){
    int aux = a[m];
    a[m] = a[n];
    a[n] = aux;
}

bool isSorted(int *a, int n){
    for(int i = 0; i < n; i++){
        if(a[i] < a[i - 1]){
                 return false;
        }
    }
    return true;
}

void insertionSort(int *a, int n){
    for (int i = 1; i < n; ++i)
    {
        for (int j = i; j > 0 && a[j] < a[j - 1]; --j)
        {
            swap(a, j, j - 1);
        }
    }
}

int sum(int a, int b){
    return a + b;
}

void selectionSort(int *a, int n){
    for (int i = 0; i < n; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        swap(a, i, min);
    }
}

int *gen_arr(size_t n){
    int *a = (int *) malloc(n * sizeof(int));
    while (n > 0)
        a[--n] = rand();
    return a;
}

void quickSort(int *a, int left, int right){
    if(left >= right)
        return;
    int v = partition(a, left, right);
    quickSort(a, left, v - 1);
    quickSort(a, v + 1, right);
}

int partition(int *a, int left, int right){

    int v = a[left];
    int i = left + 1;
    int j = right;

    while (true) {
        while (a[i] < v && i < right)
            i++;
        while (a[j] >= v && j > left)
            j--;
        if (i >= j)
            break;
        swap(a, i, j);
    }
    swap(a, left, j);
    return j;
}


