
#include "engine.h"

int main(void) {
    FILE *data;
    data = fopen("teste.in","r");

    if(data == NULL){
        printf("ERROR: Can't open the file !");
    }

    printf("========================================\n");

    int money;

    int nrTeste;
    fscanf(data,"%d", &nrTeste);
    printf("Number of tests is : %d \n", nrTeste);
    printf("========================================\n\n");

    while(nrTeste > 0){

        printf("START OF TEST %d\n\n", nrTeste);

        int i, coinType;
      //  printf("Insert money : ");
        fscanf(data,"%d", &money);
        printf("Money test = %d \n", money);

        //denomination d of the coins
        //we will start from index 1
        //so, index 0 is set to 0
        int *coinTypesArray;
        coinTypesArray = (int*) malloc(money * sizeof(int));

        //Minimum number of coins required to make change
        int *minCoin;
        minCoin = (int*) malloc(money * sizeof(int));

        //S contain the index of the coin to be included
        //in the optimal solution
        int *coinIndex;
        coinIndex = (int*) malloc(money * sizeof(int));

     //   printf("Insert number of coins type : ");
        fscanf(data ,"%d", &coinType);
        printf("There are %d coins types ! \n", coinType);

        coinTypesArray[0] = 0;

        for(i = 1; i <= coinType; i++){
      //      printf("Insert type [%d] coin : ", i);
            fscanf(data,"%d", &coinTypesArray[i]);
        }
        printf("Type of coins is : ");
        for(i = 1; i <= coinType; i++){
            printf(" %d ", coinTypesArray[i]);
        }
        printf("\n");
        //compute minimum number of coins required
        coinChange(money, coinTypesArray, coinType, minCoin, coinIndex);

        //display the content of the C array
        printf("\n minCoin[p]\n");
        display(money, minCoin);

        //display the content of the S array
        printf("\n coinIndex[p]\n");
        display(money, coinIndex);

        //display the minimum number of coins required to
        //make change for amount A
        printf("\nMin. no. of coins required to make change for amount %d = %d\n", money, minCoin[money]);

        //display the coins used in the optimal solution
        printf("\nCoin Set\n");
        coinSet(money, coinTypesArray, coinIndex);

        printf("\n\nEND OF TEST %d\n\n", nrTeste);
        printf("========================================\n\n");
        nrTeste--;


    }
	return 0;
}


