#if 0
#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(int * Array, int length) {
	for (int i = 1; i < length; i++) {
		int loc = i - 1;
		int newitem = Array[i];
		while ((loc >= 0) && (newitem < Array[loc])) {
			Array[loc + 1] = Array[loc];
			loc--;
		}
		Array[loc + 1] = newitem;
	}
}

int main(void) {
	int A[] = { 12,3,6,23,56,73,3,63,2,35,54 };
	int length = sizeof(A) / sizeof(A[0]);
	insertionSort(A, length);
	for (int i = 0;i < length;i++)
		cout << A[i] << " ";

	return 0;
}
#endif