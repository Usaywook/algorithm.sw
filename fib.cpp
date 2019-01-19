#if 0
#include<iostream>
#include<vector>
using namespace std;


// bottom-up
int bu_fibo(int n) {
	static int* fib = new int[n-1];
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2;i < n;i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	return fib[n-1];
	delete[]fib;
}

//top down


int td_fibo(int n) {
	// vector는 무조껀 0으로 초기화된다.
	static std::vector<int> table; // our cache
	if (n <= 1) {
		return n;
	}
	else if (n >= table.size()) {
		table.resize(n + 1);
	}

	if (table[n] == 0) {
		// only recalc if we don't have a value
		table[n] = td_fibo(n - 1) + td_fibo(n - 2);
	}
	return table[n];
}
int main() {

	cout << "bottom_up_method: "<< bu_fibo(10) << endl;	
	cout << "top_down_method: " << td_fibo(10) << endl;
	return 0;
}

#endif