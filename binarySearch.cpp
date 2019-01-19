#if 0
#include <iostream>
#include <array>
#include <iterator>
using namespace std;

int binarySearch(int *A, int i, int j, int x) {
	if (i > j)
		return -1;
	else {
		int mid = (i + j) / 2;
		cout << "(i, j) = " << i << "," << j << endl;
		if (x < A[mid])
			return binarySearch(A, i, mid - 1, x);
		else if (x > A[mid])
			return binarySearch(A, mid + 1, j, x);
		else
			return mid;
	}
		
}


int main() {
	int a[] = {1,2,3,5,7,9,14,17,32};
	int x;
	int length = std::size(a);
	
	cin >> x;
	cout << binarySearch(a, 0, length - 1, x);

	return 0;
}
#endif