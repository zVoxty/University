#include <iostream>
#include "engine.h"
#include <string>

using namespace std;

int secvenceExist(string mainSecv, string searchSecv) {
	int numberOfAparitions = 0;
	char firstChar = searchSecv[0];
	for (int i = 0; i < mainSecv.length(); i++) {
		if (mainSecv[i] == firstChar) {
			int index = i;
			for (int j = 0; j < searchSecv.length(); j++) {
				if (mainSecv[index] == searchSecv[j]) {
					index++;
					if (j+1 == searchSecv.length()) {
						numberOfAparitions++;
					}
				}
			}
		}
	}
	return numberOfAparitions;
}