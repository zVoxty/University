#include "engine.h"

int main()
{
    FILE *data;
    data = fopen("7.in","r");

    if(data == NULL){
        printf("ERROR: Can't open the file ! \n");
    }

    Nod *head = (Nod*)malloc(sizeof(Nod));
    head->next = NULL;

    int stramos = 1;
    int ion = 11;

    int i, j;

    int nrTests, money, nrVertices;
    int adiacentMatrix[100][100];
    int visitVector[100];
    fscanf(data,"%d", &nrTests);

    while(nrTests > 0){
        fscanf(data, "%d", &money);
        fscanf(data, "%d", &nrVertices);

        createAdiacentMatrix(data, nrVertices, adiacentMatrix, visitVector);

        printf("Adiacent mat is : \n");
        for(i = 1; i <= MAXLC; i++){
            for(j = 1; j <= MAXLC; j++){
                printf("%d", adiacentMatrix[i][j]);
            }
            printf("\n");
        }
        printf("DFS is : ");
        dfs(stramos,ion,nrVertices,head,adiacentMatrix,visitVector);
        printf("\n");
    }

    return 0;
}
