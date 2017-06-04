// LC 96, Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
// given n = 3
// Given n = 3, there are a total of 5 unique BST's.
/*
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// dp: f[n] = sum over i: f[i] * f[n - 1 - i]
// 1    2           3        4         5
// f(4) f(1)*f(3) f(2)*f(2) f(3)*f(1) f(4)*f(0)
// 1 node + (i-1) nodes
// how many ways to pick this 1 node?
// pick 1st one? last one? the other ones?
// time: O(n^2), space: O(n)
int numTrees(int n) {
    if (n <= 2) return n;
    vector<int> numOfTrees(n + 1, 0);
    numOfTrees[0] = 1;  // zero nodes
    numOfTrees[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            numOfTrees[i] += numOfTrees[j - 1] * numOfTrees[i - j];
        }
    }
    return numOfTrees[n];
}
int main() {
    int n = 3;
    int res, exp;
    res = numTrees(n);
    exp = 5;
    printf("res = %d\n", res);
    assert(res == exp);
    return 0;
}
