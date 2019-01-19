#if 1
// 결과에 대한 고찰 bottom up 방식이 가장 효율적이다.
// 하지만 코드를 짜기에는 recursive나 topdown방식이 짜기 편하다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <ctime>
#include <chrono>

using namespace std;

// matrix dynamic allocation
int** alloc2Dint(int rows, int cols) {
	if (rows <= 0 || cols <= 0) return NULL;

	int** mat = new int*[rows+1];
	for(int i=0; i<rows+1;i++){
		mat[i] = new int[cols+1];
	}
	return mat;
}

// matrix dynamic cancelation
void free2Dint(int** mat, int rows, int cols) {
	if (mat != NULL) {
		for (int i = 0;i < rows+1;i++)
			delete[]mat[i];
		delete mat;
	}
}

// print matrix values
void print2Dint(int** mat,int rows,int cols) {
	//int rows = sizeof(mat) / sizeof(mat[0]); // 3: 2차원 배열의 세로 크기를 구할 때는 
									// 배열이 차지하는 전체 공간을 가로 한 줄의 크기로 나눠줌
	//int cols = sizeof(mat[0]) / sizeof(int);    // 4: 2차원 배열의 가로 크기를 구할 때는 
												  // 가로 한 줄의 크기를 요소의 크기로 나눠줌
	printf("행의수: %d, 열의 수: %d\n", rows,cols);
	for (int i = 1;i < rows+1;i++) {
		for (int j = 1; j < cols+1; j++) 
			cout << setw(5) << mat[i][j] ;
		cout << endl;
	}
}
// initialize the matrix randomly
void set2Drandom(int** mat, int rows, int cols) {
	for (int i = 1;i < rows+1; i++) {
		for (int j = 1;j < cols + 1; j++)
			mat[i][j] = rand() % (100 - 1 + 1) + 1;
	}
}

int rec_matrixPath(int** m, int i, int j) {
	
	if (i == 0 || j == 0)
		return 0;
	else
		//cout << "(i,j) = " << "{" << i << "," << j << "}" << endl;
		return (m[i][j] + std::max(rec_matrixPath(m, i -1, j), rec_matrixPath(m, i, j - 1)));
}

// bottomup방식
int dp_bu_matrixPath(int** m, int n) {
	int ** c = alloc2Dint(n, n);
	for (int i = 0;i < n+1;i++)
		c[i][0] = 0;
	for (int j = 0;j < n+1;j++)
		c[0][j] = 0;
	for (int i = 1;i < n+1;i++)
		for (int j = 1;j < n+1;j++)
			c[i][j] = m[i][j] + max(c[i - 1][j], c[i][j - 1]);
	/*	
	cout << "c matrix" << endl;
	for (int i = 0;i < n + 1;i++) {
		for (int j = 0; j < n + 1; j++)
			cout << setw(5) << c[i][j];
		cout << endl;
	}
	*/
	int result = c[n][ n];
	free2Dint(c, n, n);
	return result;
}

int lookup(vector<vector<int>>& c, int** m, int i, int j);
// topdown방식
int dp_td_matrixPath(int** m, int i,int j) {
	vector<vector<int> >  c; //our cache!
	c.resize(j+1);
	for (int k = 0;k < j+1;k++)
		c[k].resize(i+1);
	return lookup(c, m, i, j);
	
}

int lookup(vector<vector<int>>& c,int** m, int i, int j) {
	//cout << "lookup(" << i <<","<< j << ")" << endl;
	// 저장되있다면 저장값 출력
	if (c[i][j] != 0) {
		int result = c[i][j];
		//free2Dint(c, i, j);
		return result;
	}
	//저장 안되었다면 재귀호출후 저장하고 저장값 출력
	else {
		if (i == 0 || j == 0)
			return 0;
		else
			c[i][j] = m[i][j] + max(lookup(c, m, i - 1, j), lookup(c, m, i, j - 1));
		return c[i][j];
	}
}
int main() {

	int** matrix = alloc2Dint(10, 10);
	srand((unsigned int)time(0));
	set2Drandom(matrix, 10, 10);
	//print2Dint(matrix,100 ,100);

	//chrono::system_clock::time_point start = chrono::system_clock::now();
	auto start = chrono::system_clock::now();
	cout <<"rec_maxpath value: "<< rec_matrixPath(matrix, 10, 10) << endl;
	auto end = chrono::system_clock::now();
	auto sec = chrono::duration_cast<chrono::nanoseconds>(end - start);
	cout << "Running time: " << sec.count() << "ns" << endl;

	start = chrono::system_clock::now();
	cout << "dp_bu_maxpath value: " << dp_bu_matrixPath(matrix, 10) << endl;
	end = chrono::system_clock::now();
	sec = chrono::duration_cast<chrono::nanoseconds>(end - start);
	cout << "Running time: " << sec.count() << "ns" << endl;
	
	start = chrono::system_clock::now();
	cout << "dp_td_maxpath value: " << dp_td_matrixPath(matrix ,10 ,10) << endl;
	end = chrono::system_clock::now();
	sec = chrono::duration_cast<chrono::nanoseconds>(end - start);
	cout << "Running time: " << sec.count() << "ns" << endl;

	free2Dint(matrix, 10, 10);
	return 0;
}
#endif