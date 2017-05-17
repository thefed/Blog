// LC 62, find num of unique paths in matrix from top left to bottom right
// can only go down/right
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
void print(vector<int>& v) {
	for (int i: v) printf("%d ", i);
	printf("\n");
}
// given a m x n matrix
int uniquePaths(int m, int n) {
	// numPaths[i]: the num of paths from start to col[j] at current row
	vector<int> numPaths(n, 1);	// init boundary values, at row[0]
	// print(numPaths);

	// numPaths[0] is always 1
	for (int i = 1; i < m; i++) {
		// calc row[i]
		for (int j = 1; j < n; j++) {
			numPaths[j] += numPaths[j - 1];
		}
		// print(numPaths);
	}
	return numPaths[n-1];
}
// 3 x 4 matrix
// 1 1 1 1
// 1 2 3 4
// 1 3 6 10
int main() {
	// assert(uniquePaths(10, 1) == 1);
	// assert(uniquePaths(1, 10) == 1);
	assert(uniquePaths(3, 4) == 10);
	return 0;
}