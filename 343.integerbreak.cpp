#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;
int integerBreak(int n) {
    vector<int> maxProducts(n + 1, 0);
    maxProducts[1] = 1; //
    maxProducts[2] = 1; // [3] = 2, [4] = 4, [5] = 6, [6] = 9, 
    for (int i = 3; i <= n; i++) {
        maxProducts[i] = maxProducts[i - 1];    // when j = 1
        for (int j = 2; j < i; j++) {
            maxProducts[i] = max(maxProducts[i], maxProducts[j] * max(i - j, maxProducts[i - j]));
            cout << maxProducts[i] << endl;
        }
    }
    cout << endl;
    return maxProducts[n];
}
void test() {
    int actual = integerBreak(3);
    assert(actual == 2 && "wrong output");

    actual = integerBreak(4);
    assert(actual == 4 && "wrong output");

    actual = integerBreak(10);
    assert(actual == 36 && "wrong output");
}
int main() {
    test();
}