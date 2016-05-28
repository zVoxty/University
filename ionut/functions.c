
#include "engine.h"

void coinChange(int money, int *coinTypesArray, int coinType, int *minCoin, int *coinIndex) {
	int i, p, min, coin;

	//when amount is 0
	//then min coin required is 0
	minCoin[0] = 0;
	coinIndex[0] = 0;

	for(p = 1; p <= money; p++) {
		min = INF;
		for(i = 1; i <= coinType; i++) {
			if(coinTypesArray[i] <= p) {
				if(1 + minCoin[p - coinTypesArray[i]] < min) {
					min = 1 + minCoin[p - coinTypesArray[i]];
					coin = i;
				}
			}
		}
		minCoin[p] = min;
		coinIndex[p] = coin;
	}
}

void coinSet(int money, int *coinTypesArray, int *coinIndex) {
	int a = money;
	while(a > 0) {
		printf("Use coin of denomination: %d\n", coinTypesArray[coinIndex[a]]);
		a = a - coinTypesArray[coinIndex[a]];
	}
}

void display(int money, int *arr) {
	int c;
	for(c = 0; c <= money; c++) {
		printf("%2d", arr[c]);
	}
	printf("\n");
}

