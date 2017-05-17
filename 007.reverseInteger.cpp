// LC 7, reverse an integer
#include <iostream>
#include <climits>
#include <cassert>
using namespace std;
//return 0 when the reversed integer overflows.
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

    int res = reverse(123);
    assert(res == 321);

    assert(reverse(-321) == -123);

    assert(reverse(100) == 1);

    assert(reverse(INT_MIN) == 0);

    assert(reverse(INT_MAX) == 0);

    return 0;
}
