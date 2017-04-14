#include<iostream>
#include<unordered_set>
#include<assert.h>
#include<limits.h>
using namespace std;

unordered_set<int> getPowerSet(int base) {
    unordered_set<int> set;
    for (long i = 1; i < INT_MAX; i *= base) set.insert(i);
    return set;
}

// return the max power value
int getMaxPower(int base) {
    int maxPowerVal = INT_MAX / base;
    for (int i = 1; i < INT_MAX; i *= base) if (i > maxPowerVal) return i;
    return 1;
}

bool isPowerOfThree(int n) {
    // utilize static variable to avoid redundant calculation
    //static unordered_set<int> powerSet = getPowerSet(3);
    //return powerSet.find(n) != powerSet.end();

    static int maxPowerVal = getMaxPower(3);
    return n > 0 && maxPowerVal % n == 0;
}

bool isPowerOfTree2(int n) {
    if (n > 1) {
        while (n % 3 == 0) {
            n /= 3;
        }
    }
    // else: check n == 1 or n < 1
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
