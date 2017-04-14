#include<iostream>
#include<assert.h>
using namespace std;
bool isPerfectSquare(int n) {
    if (n < 0) return false;
    if (n == 1) return true;
    long numL = n;
    int left = 0;
    int right = n;
    long root = 1;
    while (left < right) {
        long mid = (left + right) / 2;
        long tmp = mid * mid;
        //printf("mid = %ld\n", mid);
        if (tmp < numL) {
            left = mid + 1;
        }
        else if (tmp > numL) {
            right = mid - 1;
        }
        else {
            return true;
        }
        //if ((mid + 1) * (mid + 1) <= numL) {
        //    left = mid + 1;
        //}
        //else if (mid * mid <= numL) {
        //    root = mid;
        //    break;
        //}
        //else {
        //    right = mid;
        //}
    }
    return long(left) * left == n;
    //return root * root == numL;
}
int main() {
    int n = 4;
    assert(isPerfectSquare(n) == true);
    assert(isPerfectSquare(16) == true);
    assert(isPerfectSquare(17) == false);
    return 0;
}
