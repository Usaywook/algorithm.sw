#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int partition(int* Array, int p, int r) {
	int x = Array[r];
	int i = p-1;
	for (int j = p; j < r; j++) {
		if (Array[j] <= x)
			swap(Array[++i], Array[j]);
	} 
	swap(Array[i + 1], Array[r]);
	return i + 1;
}

void quickSort(int* Array,int p ,int r) {
	if (p < r) {
		int q = partition(Array,p,r);
		quickSort(Array, p, q - 1);
		quickSort(Array, q, r);
	}
}

int main(void) {
	int A[] = { 12,3,6,23,56,73,3,63,2,35,54 };
	int length = sizeof(A) / sizeof(A[0]);
	quickSort(A,0,length-1);
	for (int i = 0;i < length;i++)
		cout << A[i] << " ";

	return 0;
}
#endif