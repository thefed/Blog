// LC 85, find max rectange (made up of 1s in the matrix)
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
void print(vector<int>& v, string msg="") {
    cout << msg;
    for (int i : v) printf("%d ", i);
    printf("\n");
}
// dp
int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    // find the positon of rectangle
    //int x, y, p, q; // top left point: (x,y), bottom right: (p,q)

    // dp[i][j]: max area till position [i][j]
    // area = right[i] - left[i] * h[i]
    vector<int> left(n, 0), right(n, n - 1), height(n, 0);
    // left[i]: left boundary index of rectange at col[i], row[x]
    int maxArea = 0;
    for (int i = 0; i < m; i++) {
        int curr_left = 0, curr_right = n - 1;
            
        // compute height[i]: num of continuous rows with value 1
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') height[j]++;
            else height[j] = 0;
        }
        // compute left[i]: left boundary of rectangle at col[i]
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') left[j] = max(left[j], curr_left);
            // 1 discontinues here, next potential left border is [j+1]
            else { left[j] = 0; curr_left = j + 1; }
        }
        // compute right[i]: right border of rectangle
        for (int j = n - 1; j >= 0; j--) {
            if (matrix[i][j] == '1') right[j] = min(right[j], curr_right);
            // 1 discontinues, 
            else { right[j] = n - 1; curr_right = j - 1;  }
        }

        //print(left, "left: ");
        //print(right, "right: ");
        //print(height, "height: ");
        // update area
        for (int j = 0; j < n; j++) {
            if (height[j] == 0) continue;
            int area = (right[j] - left[j] + 1) * height[j];
            if (area > maxArea) {
                maxArea = area;
                //x = i - height[j] + 1, y = left[j], p = i, q = right[j];
            }
        }
    }
    //printf("found area at [%d][%d] -> [%d][%d]\n", x,y,p,q);
    return maxArea;
}
int main() {
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
    };
    int exp = 1;
    int res = maximalRectangle(matrix);
    printf("max rectange area: %d\n", res);
    assert(res == exp);

    matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'}
    };
    exp = 3;
    res = maximalRectangle(matrix);
    printf("max rectange area: %d\n", res);
    assert(res == exp);

    matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    exp = 6;
    res = maximalRectangle(matrix);
    printf("max rectange area: %d\n", res);
    assert(res == exp);
    return 0;
}
