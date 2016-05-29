
#include "engine.h"

int main(){
    FILE *data = fopen("testgen.in","w");

    if(data == NULL){
        printf("ERROR: Can't open the file !");
    }
        int choice;
        int money;
        printf("Insert money sum : ");
     //   money = GenerateNumber(500,1); //Enable autogenerate
        scanf("%d", &money);            //Enable keyboard
        fprintf(data,"%d \n",money);

        int coinType;
        printf("Insert coin types: ");
      //  coinType = GenerateNumber(10,1);  //Enable autogenerate
        scanf("%d", &coinType);             //Enable keyboard
        fprintf(data,"%d \n", coinType);

        if(coinType == 0){
            printf("Invalid generation, try again !");
            exit(0);
        }
        printf("Insert coins : ");
        int coins, i;
        for(i = 1; i <= coinType; i++){
         //   coins = GenerateNumber(50,i); //Enable autogenerate
            scanf("%d", &coins);            //Enable keyboard
            fprintf(data, "%d\n",coins);
        }

        fclose(data);
        FILE *data1 = fopen("testgen.in","r");

        fscanf(data1,"%d", &money);
        printf("Money test = %d \n", money);

        int *coinTypesArray;
        coinTypesArray = (int*) malloc(money * sizeof(int));

        //Minimum number of coins required to make change
        int *minCoin;
        minCoin = (int*) malloc(money * sizeof(int));

        //S contain the index of the coin to be included
        //in the optimal solution
        int *coinIndex;
        coinIndex = (int*) malloc(money * sizeof(int));

        fscanf(data1 ,"%d", &coinType);
        printf("There are %d coins types ! \n", coinType);

        coinTypesArray[0] = 0;

        printf("Type of coins is : ");
        for(i = 1; i <= coinType; i++){
            fscanf(data1,"%d", &coinTypesArray[i]);
            printf("%d ", coinTypesArray[i]);
        }

        coinChange(money, coinTypesArray, coinType, minCoin, coinIndex);

        printf("\nMin. no. of coins required to make change for amount %d = %d\n", money, minCoin[money]);

        //display the coins used in the optimal solution
        printf("\nCoin Set\n");
        coinSet(money, coinTypesArray, coinIndex);

        fclose(data1);

    return 0;
}

