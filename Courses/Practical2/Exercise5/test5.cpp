#include<iostream>
using namespace std;

bool bResizeArray(int*& pi, int& size, int sizeNew) {
	int *piNew = NULL;
	if (sizeNew <= 0 || (piNew = new int[sizeNew]) == NULL) {
		return false;
	}
	if (sizeNew > size) {
		for (int i = 0; i < size; i++) {
			piNew[i] = pi[i];
		}
		for (int i = size; i < sizeNew; i++) {
			piNew[i] = 0;
		}
	}
	else {
		for (int i = 0; i < sizeNew; i++) {
			piNew[i] = pi[i];
		}
	}

	delete[] pi;

	pi = piNew;
	size = sizeNew;

	return true;

}

int main2()
{
	int size = 10;
	int* pi = new int[size];
	for (int i = 0; i < size; i++) {
		pi[i] = i;
	}
	for (int i = 0; i < size; i++) {
		cout << pi[i] << " ";
	}
	cout << endl;

	if (bResizeArray(pi, size, 20)) {
		for (int i = 0; i < size; i++) {
			cout << pi[i] << " ";
		}
		cout << endl;
	}
	
	if (bResizeArray(pi, size, 5)) {
		for (int i = 0; i < size; i++) {
			cout << pi[i] << " ";
		}
		cout << endl;
	}

	delete[]pi;

	return 0;
}

bool bAddArrays(char*& pchs, int& size, char* pchs2, int size2) {
	
	int newSize = size + size2;
	char* pi = NULL;
	pi = new char[newSize];
	
	if (newSize <= 0 || pi == NULL) {
		return false;
	}
	else {
		for (int i = 0; i < size; i++) {
			pi[i] = pchs[i];
		}

		int j = 0;
		for (int i = size; i < newSize; i++) {		
			pi[i] = pchs2[j];
			j++;
		}

		delete[]pchs;

		size = newSize;
		pchs = pi;

		return true;
	}
}

int main()
{
	int size = 5, size2 = 5;
	char* pchs = new char[size];
	char* pchs2 = new char[size2];
	
	//pchs
	for (int i = 0; i < size; i++) {
		pchs[i] = 'a';
		cout << pchs[i] << " ";
	}
	cout << endl;
	
	//pchs2
	for (int i = 0; i < size2; i++) {
		pchs2[i] = 'b';
		cout << pchs2[i] << " ";
	}
	cout << endl;

	if (bAddArrays(pchs, size, pchs2, size2)) {
		for (int i = 0; i < size; i++) {
			cout << pchs[i] << " ";
		}
		cout << endl;
	}

	delete[]pchs;
	delete[]pchs2;

	return 0;
}