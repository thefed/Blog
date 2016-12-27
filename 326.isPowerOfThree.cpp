#include<iostream>
#include<unordered_map>
#include<assert.h>
using namespace std;
unordered_map<int, int> getPowerSet(int base) {
    unordered_map<int, int> set;
    for (long i = 1; i < INT_MAX; i *= base) {
        set[i] = 1;
    }
    return set;
}
bool isPowerOfThree(int n) {
    static unordered_map<int, int> powerSet = getPowerSet(3);
    return powerSet.find(n) != powerSet.end();
}
bool isPowerOfTree2(int n) {
    if (n > 1) {
        while (n % 3 == 0) {
            n /= 3;
        }
    }
    return n == 1;
}
int main() {
    int n = 0;
    assert(isPowerOfThree(n) == false);
    n = -1;
    assert(isPowerOfThree(n) == false);
    n = 1;
    assert(isPowerOfThree(n) == true);
    n = 243;
    assert(isPowerOfThree(n) == true);
    return 0;
}
