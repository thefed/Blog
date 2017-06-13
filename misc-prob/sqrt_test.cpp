// impl sqrt, return int / double
#include <iostream>
#include <cmath>      // sqrt
#include <cassert>
using namespace std;

// return the last integer n, where n^2 <= x
int sqrt_int(int x) {
    long start = 1;
    long end = x;
    while (start + 1 < end) {
        long mid = start + (end - start) / 2;
        if (mid * mid <= x) {
            start = mid;
        }
        else {
            end = mid;
        }
    }
    return (end * end <= x) ? int(end): int(start);
}

// follow-up, return the double type sqrt of x
double sqrt_d(int x) {
    double start = 1;
    double end = x;
    while ((end - start) > 1e-6) {
        double mid = start + (end - start) / 2;
        if (mid * mid <= x) {
            start = mid;
        }
        else {
            end = mid;
        }
    }
    return (end * end <= x) ? end: start;
}

void testSqrt() {
    int x = 122;
    int r = (int) sqrt(x);
    printf("sqrt_int(%d): %d\n", x, r);
    assert(sqrt_int(x) == r);
}

void testsqrt_d() {
    int x = 122;
    double r = sqrt(double(x));
    double actual = sqrt_d(x);
    printf("sqrt_d(%d): actual: %f, expected: %f\n", x, actual, r);
    assert(actual - r < 1e-4);
}

int main() {
    cout << "/*\n";
    testSqrt();
    testsqrt_d();
    cout << "*/\n";
}
/*
sqrt_int(122): 11
sqrt_d(122): actual: 11.045361, expected: 11.045361
*/
