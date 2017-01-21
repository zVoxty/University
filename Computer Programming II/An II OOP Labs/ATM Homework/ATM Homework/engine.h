#pragma once
#include "engine.h"
#include "Bank.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void intro();
void fetchDatabase(vector<Bank> users);

int getSizeOfDatabase();