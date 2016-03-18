/* 
*  Lab functions by Vasile Sebastian Costinel.
*  To test this use test() statement.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bridge.h"
#include <time.h>
#include <windows.h>

void test() {
	printf("Test Solved 1 ! \n");
}

int mergeSort(int* a, int len) {
	int step = 1;
	int *m1 = (int *)malloc(len*sizeof(int));
	if (!m1) return -1;
	int *m2 = (int *)malloc(len*sizeof(int));
	if (!m2) return -1;
	while (step < len) {
		int i, s1, e1, s2, e2;
		for (i = 0; (i + step - 1) < (len - 1); i += 2 * step) {
			s1 = i;
			e1 = i + step - 1;
			s2 = e1 + 1;
			(i + 2 * step - 1) < (len - 1) ? (e2 = i + 2 * step - 1) : (e2 = len - 1);
			merge(a, s1, e1, s2, e2, m1, m2);
		}
		step = step << 1;
	}
	return 0;
}

int merge(int *a, int s1, int e1, int s2, int e2, int* m1, int* m2) {
	int len1 = e1 - s1 + 1;
	int len2 = e2 - s2 + 1;
	int p1 = 0;
	int p2 = 0;
	int p = s1;
	memcpy(m1, a + s1, sizeof(int)*len1);
	memcpy(m2, a + s2, sizeof(int)*len2);
	while (p1<len1 && p2<len2) {
		if (m1[p1] < m2[p2]) {
			a[p++] = m1[p1++];
		}
		else {
			a[p++] = m2[p2++];
		}
	}
	while (p1<len1) {
		a[p++] = m1[p1++];
	}
	while (p2<len2) {
		a[p++] = m2[p2++];
	}
	return 0;
}

void createArray(int *a, int n) {
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}

void printArray(int *a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

bool isSorted(int *a, int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] < a[i - 1]) {
			return false;
		}
	}
	return true;
}

void insertionSort(int *a, int n) {
	for (int i = 1; i < n; ++i)
	{
		for (int j = i; j > 0 && a[j] < a[j - 1]; --j)
		{
			swap(a, j, j - 1);
		}
	}
}

void selectionSort(int *a, int n) {
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

int quicksort(int*a, int len){
    quicksort_r(a,0,len-1);
    return 0;
}
int quicksort_r(int* a,int start,int end){
    if (start>=end) {
        return 0;
    }
    int pivot=a[end];
    int swp;
    //set a pointer to divide array into two parts
    //one part is smaller than pivot and another larger
    int pointer=start;
    int i;
    for (i=start; i<end; i++) {
        if (a[i]<pivot) {
            if (pointer!=i) {
                //swap a[i] with a[pointer]
                //a[pointer] behind larger than pivot
                swp=a[i];
                a[i]=a[pointer];
                a[pointer]=swp;
            }
            pointer++;
        }
    }
    //swap back pivot to proper position
    swp=a[end];
    a[end]=a[pointer];
    a[pointer]=swp;
    quicksort_r(a,start,pointer-1);
    quicksort_r(a,pointer+1,end);
    return 0;
}
