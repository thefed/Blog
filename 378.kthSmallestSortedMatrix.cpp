// LC 378, find k-th smallest element in a sorted matrix
// matrix: each row is sorted, each col is sorted (ASC)
// Note that it is the kth smallest element in the sorted order, not the kth distinct element.
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
int kthSmallest(vector<vector<int>>& matrix, int k){
    const int m = matrix.size();
    const int n = matrix[0].size();
    int low = matrix[0][0];
    int high = matrix[m - 1][n - 1];
    while (low < high) {
        printf("low: %d, high: %d, ", low, high);
        int mid = low + (high - low) / 2;
        int j = n - 1;
        int smallerCnt = 0; // num of elements <= mid
        for (int i = 0; i < m; i++) {
            while (j >= 0 && matrix[i][j] > mid) j--;
            smallerCnt += (j + 1);
        }
        printf("samllerCnt: %d, mid: %d\n", smallerCnt, mid);
        if (smallerCnt < k) low = mid + 1;
        else high = mid;
    }
    return low;
}
int main() {
    vector<vector<int>> matrix = {
        {1,5,9},
        {10,11,13},
        {12,13,15}
    };
    vector<int> exps = {1,5,9,10,11,12,13,13,15};
    for (int i = 0; i < exps.size(); i++) {
        int k = i + 1;
        int res = kthSmallest(matrix, k);
        printf("\ntest %d, res: %d\n\n", i + 1, res);
        assert(res == exps[i]);
    }
    
    return 0;
}