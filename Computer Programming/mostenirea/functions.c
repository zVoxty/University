#include "engine.h"

void createAdiacentMatrix(FILE *data, int nrVertices, int adiacentMatrix[100][100],int visitVector[100]){
    int i , j, father, son;

    for(i = 1; i < MAXLC; i++){
        for(j = 1; j < MAXLC; j++){
            adiacentMatrix[i][j] = 0;
            visitVector[i] = 0;
        }
    }

    for(i = 1; i <= nrVertices; i++){
        fscanf(data,"%d %d", &father, &son);
        adiacentMatrix[father][son] = 1;
    }
}

void push_first(Nod *head, int value){
    Nod *newNod;
    newNod =(Nod*)malloc(sizeof(Nod));
    newNod->data = value;
    newNod->next = head->next;
    head->next = newNod;
}

void pop_first(Nod *head){
    int value;
    Nod *deleted;
    deleted = head->next;
    value = deleted->data;
    head->next = deleted->next;
    return value;
}

int pop_back(Nod *head){
    Nod *iterator = head;
    Nod *valDel;
    int val;
    while(iterator->next->next != NULL){
        iterator = iterator->next;
    }
    valDel = iterator->next;
    val = valDel->data;
    iterator = valDel->next;
    free(valDel);
    return val;
}

void dfs(int stramos, int ion, int vertices, Nod *head, int adiacentMatrix[100][100], int visitVector[100]){
    int root = stramos;
    int i;
    push_first(head, stramos);

    while(head->next != NULL){
        root = pop_back(head);
        visitVector[root] = 1;
        printf(" %d ", root);

        for(i = 1; i <= MAXLC; i++){
            if(adiacentMatrix[root][i] == 1 && visitVector[i] == 0){
                push_first(head, i);
            }
        }
    }
    for(i = 1; i <= MAXLC; i++){
        visitVector[i] = 0;
    }
}
