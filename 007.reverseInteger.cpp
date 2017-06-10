// LC 7, reverse an integer
// 123 => 321
// -123 => -321
// 10 0000 0003 => 30 0000 0001 ? if overflowed, return 0
#include <iostream>
#include <climits>
#include <cassert>
#include <vector>
using namespace std;
//return 0 when the reversed integer overflows
// use a long type to store result to handle overflow
int reverse(int x) {
    long res = 0;
    while (x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return (res > INT_MAX || res < INT_MIN) ? 0 : res;
}
int main() {
    for (int i = -9; i <= 9; i++) assert(reverse(i) == i);

    vector<int> nums = {123, -321, 100, 1000000003, -1000000003, INT_MAX, INT_MIN};
    vector<int> exp = {321, -123, 1, 0, 0, 0, 0};
    for (int i = 0; i < nums.size(); i++) {
        int res = reverse(nums[i]);
        printf("reverse %d => %d\n", (int)nums[i], res);
        assert(res == exp[i]);
    }
    return 0;
}
