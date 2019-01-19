#if 0
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int partition(int* Array, int p, int r) {
	int x = Array[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (Array[j] <= x)
			swap(Array[++i], Array[j]);
	}
	swap(Array[i + 1], Array[r]);
	return i + 1;
}

int avg_linear_select(int* arr, int p, int r, int i){
	if (p == r)
		return arr[p];
	else {
		int q = partition(arr, p, r);
		int k = q - p + 1;
		if (i < k)
			return avg_linear_select(arr, p, q - 1, i);
		else if (i > k)
			return avg_linear_select(arr, q + 1, r, i - k);
		else
			return arr[q];

	}
}

int main() {

	int arr[] = { 31,8,48,73,11,3,20,29,65,15 };
	int length = size(arr);
	int x;
	cout << "몇번째 작은 원소를 찾을까요? " << endl;
	cin >> x;
	int result = avg_linear_select(arr, 0, length - 1, x);
	cout << result << endl;
	return 0;
}
#endif