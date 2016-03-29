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
		}
		printf("and there are %d numbers", iterator);
		printf("\n");
		Sleep(2000);
		return iterator;
	}
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
		}
	}
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
		}	
	}
}

int get_max(stk *head) {    
	stk *curent = head->next;
	int temp = 0;
	while (curent->next != NULL) {
		if (temp > curent->data) {
			temp = curent->data;
			curent = curent->next;
		}
		else {
			curent = curent->next;
		}
	}
	printf("Max element is %d !\n", temp);
	Sleep(2000);
	return temp;
}  /* LOGIC PROBLEM */

int get_min(stk *head) {
	stk *curent = head->next;
	int temp = 0;
	while (curent->next != NULL) {
		if (curent->data < curent->next->data) {
			temp = curent->data;
		}
		else {
			temp = curent->next->data;
		}
		curent = curent->next;
	}
	printf("Min element is %d !\n", temp);
	Sleep(2000);
	return temp;
}   /* LOGIC PROBLEM */

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
			printf("Value of %d este pe pozitia %d !", current->data, i);
			Sleep(3000);
			break;
		}
	}

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
		}
	}
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
		}
	}
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

/* END OF STORT FUNCTIONS */

/*--------------------------------------*/
/*XXXXXXXXX>> Writed By Voxty <<XXXXXXXX*/
/*--------------------------------------*/

/* SIMPLE FUNCTIONS*/

/* Function which create an array */
void createArray(int *a, int n) {
	int i;
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
}

/* Function which print an array */
void printArray(int *a, int n) {
	int i;
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