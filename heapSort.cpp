#if 0
#include <iostream>
#include <algorithm>
using namespace std;

void heapify(int* A, int k, int n);

void buildHeap(int* A, int n) {
	for (int i = (n-1) / 2;i >= 0; i--) {
		heapify(A, i, n-1);
	}
}

void heapify(int* A, int k, int n) {
	int left = 2*k;
	int right = 2*k + 1;
	int smaller = 0;

	if (right <= n) {
		if (A[left] < A[right])
			smaller = left;
		else
			smaller = right;
	}
	else if (left <= n)
		smaller = left;
	else
		return;
	if (A[smaller] < A[k]) {
		swap(A[k], A[smaller]);
		heapify(A, smaller, n);
	}
}

void heapSort(int* A, int n) {
	buildHeap(A, n);
	for (int i = n - 1; i > 0; i--) {
		swap(A[0], A[i]);
		heapify(A, 0, i - 1);
	}
}

int main(void) {
	int Array[] = { 12,3,6,23,56,73,3,63,2,35,54 };
	int length = sizeof(Array) / sizeof(Array[0]);
	heapSort(Array, length);
	//buildHeap(Array, length);
	for (int i = 0; i < length; i++) {
		cout << Array[i] << " ";
	}

	return 0;
}
#endif