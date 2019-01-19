#if 0
#include <iostream>
#include <algorithm>

using namespace std;

int thelargest(int *Array, int length);

void selectionSort(int* Array, int length) {
	for (int i = length-1; i > 1; i--) {
		int k = thelargest(Array, i);
		swap(Array[i],Array[k]);
	}
}

int thelargest(int *Array, int length) {
	int largest = 0;
	for (int i = 0;i < length; i++) {
		if (Array[i] > Array[largest])
			largest = i;
	}
	return largest;
}
int main(void) {
	int A[] = { 12,3,6,23,56,73,3,63,2,35,54 };
	int length = sizeof(A) / sizeof(A[0]);
	selectionSort(A, length);
	for (int i = 0;i < length;i++)
		cout << A[i] << " ";

	return 0;
}
#endif