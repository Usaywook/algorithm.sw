#if 0
#include <iostream>
#include <iomanip>
using namespace std;
//int tempArray[100];


void merge(int* Array, int p, int q, int r) {
	int i = p;
	int j = q + 1;

	int t = 0;
	
	int* tempArray = new int[r-p+1];
	

	while (i <= q && j <= r) {
		if (Array[i] <= Array[j])
			tempArray[t++] = Array[i++];
		else
			tempArray[t++] = Array[j++];
	}
	while (i <= q)
		tempArray[t++] = Array[i++];
	while (j <= r)
		tempArray[t++] = Array[j++];
	i = p;
	t = 0;

	/*
	for (int k = 0; k< r - p + 1; ++k) {
		cout << tempArray[k] << setw(4);
	}cout << endl;
	*/

	while (i <= r)
		Array[i++] = tempArray[t++];

	delete []tempArray;
}

void mergeSort(int* Array, int p, int r) {
	int q = (p + r) / 2;
	if(p<r){
		mergeSort(Array, p, q);
		mergeSort(Array, q + 1, r);
		merge(Array, p, q, r);
	}
}

int main(void) {
	int A[] = { 12,3,6,23,56,73,3,63,2,35,54 };
	//int A[] = {3,8,31,65,73,11,15,20,29,48};
	int length = sizeof(A) / sizeof(A[0]);
	//merge(A, 0, 4, 9);

	mergeSort(A, 0, length - 1);
	for (int i = 0; i < length; i++) {
		cout << A[i] << " ";

	}
	return 0;
}
#endif
