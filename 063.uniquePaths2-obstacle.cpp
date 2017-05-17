// LC 63, find num of unique paths in matrix from top left to bottom right
// can only go down/right
// but matrix has obstacles (0: can go;  1: occupied, can not go)
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
void print(vector<int>& v) {
	for (int i: v) printf("%d ", i);
	printf("\n");
}
// given a m x n matrix, 
// O(n) space dp
int uniquePaths(vector<vector<int>> matrix) {
	// numPaths[i]: the num of paths from start to col[j] at current row
	// init boundary values, at row[0]
	const int m = matrix.size(), n = matrix[0].size();
	vector<int> numPaths(n, 1);	

	for (int i = 0; i < n; i++) {
		if (matrix[0][i] == 1) {	// set all other items as 0
			while (i < n) numPaths[i++] = 0;
		}
	}
	// print(numPaths);

	// numPaths[0] is always 1
	for (int i = 1; i < m; i++) {
		// calc row[i]
		// col[0]: 1 or 0?
		if (matrix[i][0] == 1) numPaths[0] = 0;

		// col [1..n-1]
		for (int j = 1; j < n; j++) {
			if (matrix[i][j] == 1) numPaths[j] = 0;
			else {
				numPaths[j] += numPaths[j - 1];
			}
		}
		// print(numPaths);
	}
	return numPaths[n-1];
}
// 3 x 3 matrix
// 1 1 1 
// 1 0 1
// 1 1 2

int main() {
	vector<vector<int>> matrix = {
		{0,0,0}, {0,1,0}, {0,0,0}
	};
	// assert(uniquePaths(10, 1) == 1);
	// assert(uniquePaths(1, 10) == 1);
	assert(uniquePaths(matrix) == 2);

	matrix = {
		{0,1,0,0},
		{0,1,0,0},
		{1,0,0,0}
	};
	assert(uniquePaths(matrix) == 0);
	return 0;
}