#if 0
#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(int * Array, int length) {
	for (int j = length; j > 1; j--) {
		bool Sorted = true;
		for (int i = 0; i < j - 1; i++) {
			if (Array[i] > Array[i + 1]){
				swap(Array[i], Array[i + 1]);
				Sorted = false;
			}
		}
		if (Sorted == true) break;
	}
}

int main(void) {
	int A[] = { 12,3,6,23,56,73,3,63,2,35,54 };
	int length = sizeof(A) / sizeof(A[0]);
	bubbleSort(A, length);
	for (int i = 0;i < length;i++)
		cout << A[i] << " ";

	return 0;
}
#endif