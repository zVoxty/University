#ifndef BRIDGE_H_INCLUDED
#define BRIDGE_H_INCLUDED

struct stack {
	int data;
	struct stack *next;
};

struct heap {
	int data;
	struct heap *dr;
	struct heap *st;
};

typedef struct stack stk;
typedef struct heap hp;

/* QUICK-CALL << STACK AND QUE FUNCTIONS >> */

void STACKS_AND_QUE();
int show_list(stk *head);
int get_max(stk *head);
int get_min(stk *head);
void push_back(stk *head);
void pop_back(stk *head);
void pop_first(stk *head);
void check_is_sorted(stk *head);
void COADA(stk *head);
void STACKS(stk *head);

/* END OF QUICK-CALL << STACK AND QUE FUNCTIONS >> */

/*--------------------------------------*/
/*XXXXXXXXX>> Writed By Voxty <<XXXXXXXX*/
/*--------------------------------------*/

/* STORT FUNCTIONS */

void selectionSort(int *a, int n);

/* END OF STORT FUNCTIONS */

/*--------------------------------------*/
/*XXXXXXXXX>> Writed By Voxty <<XXXXXXXX*/
/*--------------------------------------*/

/* SIMPLE FUNCTIONS*/

void swap(int *a, int *b);
void createArray(int *a, int n);
void printArray(int *a, int n);

/* END OF SIMPLE FUNCTIONS*/

#endif // !BRIDGE_H_INCLUDED
