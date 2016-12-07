#include<iostream>  // cout
#include<math.h>      // sqrt
#include<assert.h>  // assert
using namespace std;

// find the last number n such that n ^ 2 <= x
int sqrt1(int x);
// followup, return a double type sqrt of x
double sqrt2(int x);
void testSqrt();
void testSqrt2();

int main() {
    cout << "/*\n";
    testSqrt();
    testSqrt2();
    cout << "*/\n";
}

int sqrt1(int x) {
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

double sqrt2(int x) {
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
    cout << "** testSqrt **\n";
    int x = 122;
    int r = (int) sqrt(x);
    assert(sqrt1(x) == r);
    cout << "SUCCESS\n";
}

void testSqrt2() {
    cout << "** testSqrt2 **\n";
    int x = 122;
    double r = sqrt(double(x));
    double actual = sqrt2(x);
    printf("actual: %f, expected: %f\n", actual, r);
    assert(actual - r < 1e-4);
    cout << "SUCCESS\n";
}
/*
** testSqrt **
SUCCESS
** testSqrt2 **
actual: 11.045361, expected: 11.045361
SUCCESS
*/
