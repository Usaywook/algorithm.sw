#if 1
#include <iostream>
#include <algorithm>
#include <iterator>
#include <tuple>
#include <vector>

using namespace std;

//int max(int a, int b, int c) { return std::max(std::max(a, b), c); }
tuple<int,int,int> maxCrossingSum(int* arr, int l, int m, int h)
{
	// Include elements on left of mid. 
	int sum = 0;
	int left_sum = INT_MIN;
	int max_left = l;
	int max_right = h;
	for (int i = m; i >= l; i--)
	{
		sum = sum + arr[i];
		if (sum > left_sum) {
			left_sum = sum;
			max_left = i;
		}
	}

	// Include elements on right of mid 
	sum = 0;
	int right_sum = INT_MIN;
	for (int i = m + 1; i <= h; i++)
	{
		sum = sum + arr[i];
		if (sum > right_sum) {
			right_sum = sum;
			max_right = i;
		}
	}

	// Return sum of elements on left and right of mid 
	return make_tuple(max_left, max_right, left_sum + right_sum);
}

// Returns sum of maxium sum subarray in aa[l..h] 
tuple<int,int,int> maxSubArraySum(int* arr, int l, int h)
{
	// Base Case: Only one element 
	if (l == h)
		return make_tuple(l,h,arr[l]);

	else{
		// Find middle point 
		int m = (l + h) / 2;

		/* Return maximum of following three possible cases
			a) Maximum subarray sum in left half
			b) Maximum subarray sum in right half
			c) Maximum subarray sum such that the subarray crosses the midpoint */
		tuple<int, int, int> left_half = maxSubArraySum(arr, l, m);
		tuple<int, int, int> right_half = maxSubArraySum(arr, m + 1, h);
		tuple<int, int, int> cross = maxCrossingSum(arr, l, m, h);

		// auto 자동 지역 변수 자료형 
		std::vector<int> v{get<2>(left_half), get<2>(right_half), get<2>(cross)};
		auto mm = std::minmax_element(v.begin(), v.end());
		auto idx_min = std::distance(v.begin(), mm.first);
		auto idx_max = std::distance(v.begin(), mm.second);

		switch (idx_max)
		{
		case 0:
			return left_half;
			break;
		case 1:
			return right_half;
			break;
		case 2:
			return cross;
			break;
		default:
			cout << "error" << endl;
			break;
		}

	}
}

//incremental algorithm
tuple<int,int,int> inc_max_array_sum(int *arr, int n) {
	int thissum = 0;
	int maxsum = 0;
	int low = 0;
	int high = n - 1;

	for (int i = 0;i < n;i++) {
		thissum = thissum + arr[i];
		if (thissum > maxsum){
			maxsum = thissum;
			high = i;
		}
		else if (thissum < 0) {
			thissum = 0;
			low = i+1;
		}
	}
	return make_tuple(low, high, maxsum);
}

int main() {

	int arr[] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
	int n = size(arr);
	int low = 0;
	int high = n - 1;
	tuple<int,int,int> result = maxSubArraySum(arr, 0, n - 1);
	//tuple<int, int, int> result = inc_max_array_sum(arr, n - 1);

	cout << "(low ,high) index is " << "(" << get<0>(result) << "," << get<1>(result) << ")"<<endl;
	cout << "Maximum contiguous sum is " << get<2>(result) << endl;
	return 0;
}
#endif

