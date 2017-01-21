#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template<class T>

class Sort
{
public:
	Sort() {

	}
	~Sort() {

	}

private:
	vector<T> myArray;
	int n;
public:
	void create() {
		cout << "How much elements : ";
		cin >> n;

		for (int i = 0; i < n; i++) {
			cout << "Element " << i + 1 << " : ";
			T element;
			cin >> element;
			myArray.push_back(element);
		}
		cout << endl;
	}

	void Print() {
		cout << "Printing array : \n";
		for (int i = 0; i < myArray.size(); i++)
			cout << myArray[i] << " ";
		cout << endl;
	}

	void SortElem() {
		sort(myArray.begin(), myArray.end());
	}
};


class Matrix
{
public:
	Matrix() {

	}
	~Matrix() {

	}
private:
	int dimensiune;
	int one;
	int two;
	int three;
	int four;
	int matrix[100][100];
public:
	int sum = 0;

	friend istream& operator >> (istream & cin, Matrix & w){
		cin >> w.dimensiune;
		int i, j;
		for (i = 0; i < w.dimensiune; i++) {
			for (j = 0; j < w.dimensiune; j++) {
				cin >> w.matrix[i][j];
				w.sum += w.matrix[i][j];
			}
		}
		return cin;
	}

	friend ostream & operator << (ostream & cout, Matrix & w) {
		int i, j;
		for (i = 0; i < w.dimensiune; i++) {
			for (j = 0; j < w.dimensiune; j++) {
				cout << w.matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << "\n\n";
		return cout;
	}

	friend bool operator<(Matrix & matrixOne, Matrix & matrixTwo) {
		return matrixOne.sum < anotherMatrix.sum;
	}

	void CreateMatrix() {
		cout << "Matrix Dimension : ";
		cin >> dimensiune;
		for (int i = 0; i < dimensiune; i++) {
			for (int j = 0; j < dimensiune; j++) {
				cout << "Element [" << i << "][" << j << "] : ";
				cin >> matrix[i][j];
				sum += matrix[i][j];
			}
		}
	}

	void PrintMatrix() {
		for (int i = 0; i < dimensiune; i++){
			for (int j = 0; j < dimensiune; j++){
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << "\n\n";
	}
};
