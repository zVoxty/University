#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "bridge.h"
#include <stdbool.h>

/*--------------------------------------*/
/*XXXXXXXXX>> Writed By Voxty <<XXXXXXXX*/
/*--------------------------------------*/

/* A HOLE LIB OF << STACK AND QUE FUNCTIONS >> */

int show_list(stk *head) {
	int iterator = 0;
	if (head->next != NULL) {
		printf("List is : ");
		stk *curent = head;
		while (curent->next != NULL) {
			iterator++;
			curent = curent->next;
			printf("%d ", curent->data);
		}/* End of while */
		
		printf("and there are %d numbers", iterator);
		printf("\n");
		Sleep(2000);
		return iterator;
	}/* End of if */
	
	else {
		printf(" There are no values !!! \n");
		Sleep(2000);
	}
}

void STACKS_AND_QUE(){
	stk *head;
	head = (stk*)malloc(sizeof(stk));
	head->next = NULL;

	int option = 1;
	int chose;

	while (option) {
		system("CLS");

		printf("          STACKS & QUEUE \n");
		printf("---------------------------------------\n");
		printf("	1. STACKS \n");
		printf("	2. QUEUE \n");
		printf("	3. EXIT \n");
		printf("	Insert your choice : \n");
		scanf("%d", &chose);

		switch (chose) {
		case 1:
			STACKS(head);
		case 2:
			COADA(head);
		case 3:
			option = 0;
		default:
			printf(" Wrong choice ! ");
			Sleep(2000);
			break;
		}/* End of switch */
	}/* End of while */
}

bool check_is_sorted(stk *head) {
	stk *current = head;
	int ok = 0;
	if (head->next == NULL) {
		printf("List is empty ! \n");
		Sleep(2000);
	}
	else {
		while (current->next != NULL) {
			if (current->data < current->next->data) {
				current = current->next;
				if (current->next == NULL) {
					printf("List is sorted ! \n");
					Sleep(2000);
					return true;
				}
			}
			else {
				printf("List is not sorted ! \n");
				Sleep(2000);
				return false;
			}
		}/* End of while */	
	}/* End of else */
}

int get_max(stk *head) {    
	stk *current = head->next;
	int temp = 0;
	while (current->next != NULL) {
		if (current->data > temp) {
			temp = current->data;
		}
		current = current->next;
	}
	printf("Maxim number in array is : %d \n", temp);
	Sleep(2000);
	return temp;
} 

int get_min(stk *head) {
	stk *current = head->next;
	int temp = 1000000;
	while (current->next != NULL) {
		if (temp > current->data) {
			temp = current->data;
		}
		current = current->next;
	}
	printf("Min element is %d !\n", temp);
	Sleep(2000);
	return temp;
}

void binary_search(stk *head) {
	int val;
	int i = 0;
	stk *current = head;

	printf("What do you want to find : \n");
	scanf("%d", &val);

	while (current->next != NULL) {
		if (current->data != val) {
			current = current->next;
			i++;
		}
		else {
			printf("Value of %d have position %d !", current->data, i);
			Sleep(3000);
			break;
		}
	}/* End of while */
}

void push_back(stk *head) {
	int value;
	do {
		printf("Insert value (0 = back to main): ");
		scanf("%d", &value);
		if (value != 0) {
			stk *current = head;

			stk *new_value;
			new_value = (stk*)malloc(sizeof(stk));

			while (current->next != NULL) {
				current = current->next;
			}
			current->next = new_value;
			new_value->data = value;
			new_value->next = NULL;
		}
	} while (value != 0);
}

void pop_first(stk *head) {
	if (head->next == NULL) {
		printf(" List is empty ! \n");
		Sleep(2000);
	}
	else {
		stk *val;
		stk *leg;
		val = head->next;
		leg = val->next;
		printf(" Value of %d was been deleted !", val->data);
		Sleep(2000);
		free(val);
		head->next = leg;
	}
}

void pop_back(stk *head) {
	if (head->next == NULL) {
		printf("List is Empty ! \n");
		Sleep(2000);
	}
	else {
		stk *curent = head;
		stk *val_del;
		while (curent->next->next != NULL) {
			curent = curent->next;
		}
		val_del = curent->next;
		printf("Value of %d was been deleted !", val_del->data);
		Sleep(2000);
		free(val_del);
		curent->next = NULL;
	}
	
}

void STACKS(stk *head) {

	int option = 1;
	int chose;

	while (option) {
		system("CLS");

		printf("             STACKS\n");
		printf("--------------------------------\n");
		printf("	1. PUSH \n");
		printf("	2. POP\n");
		printf("	3. SHOW MAX\n");
		printf("	4. SHOW MIN\n");
		printf("	5. SHOW\n");
		printf("	6. BACK TO MAIN\n");
		printf("	Insert you choice : ");
		scanf("%d", &chose);

		switch (chose) {
		case 1:
			push_back(head);
			break;
		case 2:
			pop_back(head);
			break;
		case 3:
			get_max(head);
			break;
		case 4:
			get_min(head);
			break;
		case 5:
			show_list(head);
			break;
		case 6:
			main();
		default:
			printf("Wrong choice ! \n");
			Sleep(2000);
			break;
		}/* End of switch */
	}/* End of while */
}

void COADA(stk *head) {
	int option = 1;
	int chose;

	while (option) {
		system("CLS");

		printf("             QUE\n");
		printf("--------------------------------\n");
		printf("	1. PUSH \n");
		printf("	2. POP\n");
		printf("	3. SHOW MAX\n");
		printf("	4. SHOW MAX\n");
		printf("	5. SHOW\n");
		printf("	6. BACK TO MAIN\n");
		printf("	Insert you choice : ");
		scanf("%d", &chose);

		switch (chose) {
		case 1:
			push_back(head);
			break;
		case 2:
			pop_first(head);
			break;
		case 3:
			get_max(head);
			break;
		case 4:
			get_min(head);
			break;
		case 5:
			show_list(head);
			break;
		case 6:
			main();
		default:
			printf("Wrong choice ! \n");
			Sleep(2000);
			break;
		}/* End of switch */
	}/* End of while */
}

/* END OF << STACK AND QUE FUNCTIONS >> */

/*--------------------------------------*/
/*XXXXXXXXX>> Writed By Voxty <<XXXXXXXX*/
/*--------------------------------------*/

/* STORT FUNCTIONS */

void selectionSort(int *a, int n) {
	int i, j;

	for (i = 0; i < n; ++i) {
		int min = i;
		for (j = i + 1; j < n; ++j) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		swap(&i, &min);
	}
}

void heapify(int *a, int n, int i)
{
	int largest = i;  // Initialize largest as root
	int l = 2 * i + 1;  // left = 2*i + 1
	int r = 2 * i + 2;  // right = 2*i + 2

						// If left child is larger than root
	if (l < n && a[l] > a[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && a[r] > a[largest])
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(&a[i], &a[largest]);

		// Recursively heapify the affected sub-tree
		heapify(a, n, largest);
	}
}

void heapSort(int *a, int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end
		swap(&a[0], &a[i]);

		// call max heapify on the reduced heap
		heapify(a, i, 0);
	}
}

void Merge(int *A, int *L, int leftSize, int *R, int rightSize) {
	int i, j, k;

	i = 0; j = 0; k = 0;

	while (i<leftSize && j< rightSize) {
		if (L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while (i < leftSize) A[k++] = L[i++];
	while (j < rightSize) A[k++] = R[j++];
}

void mergeSort(int *A, int size) {
	int i, mid, *L, *R;
	if (size < 2) return;

	mid = size / 2;

	L = (int*)malloc(mid*sizeof(int));
	R = (int*)malloc((size - mid)*sizeof(int));

	for (i = 0; i<mid; i++) L[i] = A[i];
	for (i = mid; i<size; i++) R[i - mid] = A[i];

	mergeSort(L, mid);
	mergeSort(R, size - mid);
	Merge(A, L, mid, R, size - mid);
	free(L);
	free(R);
}

int quicksort(int*a, int len) {
	quicksort_r(a, 0, len);
	return 0;
}

int quicksort_r(int* a, int start, int end) {
	if (start >= end) {
		return 0;
	}
	int pivot = a[end];
	int swp;
	//set a pointer to divide array into two parts
	//one part is smaller than pivot and another larger
	int pointer = start;
	int i;
	for (i = start; i<end; i++) {
		if (a[i]<pivot) {
			if (pointer != i) {
				//swap a[i] with a[pointer]
				//a[pointer] behind larger than pivot
				swp = a[i];
				a[i] = a[pointer];
				a[pointer] = swp;
			}
			pointer++;
		}
	}
	//swap back pivot to proper position
	swp = a[end];
	a[end] = a[pointer];
	a[pointer] = swp;
	quicksort_r(a, start, pointer - 1);
	quicksort_r(a, pointer + 1, end);
	return 0;
}

/* END OF STORT FUNCTIONS */

/*--------------------------------------*/
/*XXXXXXXXX>> Writed By Voxty <<XXXXXXXX*/
/*--------------------------------------*/

/* SIMPLE FUNCTIONS*/

/* Function which create an array */
void createArray(int *a, int n) {
	int i;
	printf("Insert %d elements in array : ", n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
}

/* Function which print an array */
void printArray(int *a, int n) {
	int i;
	printf("Your array have %d elements and here are : \n", n);
	for (i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
}

/* Function which swap two elements !*/
void swap(int *a,int  *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/* END OF SIMPLE FUNCTIONS*/
