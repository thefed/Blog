// LC 50, impl pow(x, y)
// double myPow(double x, int n)
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;
// binary search
double myPow(double x, int n) {
    if (x == 1 || n == 0) return 1;
    if (x == -1) return n & 1 ? -1 : 1;
    if (n < 0) {
        n = (n == INT_MIN ? INT_MAX : -n);  // adjust n
        x = 1 / x;
    }
    return (n & 1) ? x * myPow(x * x, n / 2) : myPow(x * x, n / 2);
}
int main() {
    vector<double> x = {1, 2, 2, 2,2, -1};
    vector<int> n =   {-1, 0, 5,-5,INT_MIN, INT_MIN};
    vector<double> exps = {1, 1, 32,pow(2,-5),0, 1};
    for (int i = 0; i < x.size(); i++) {
        double res = myPow(x[i], n[i]);
        assert(res == exps[i]);
    }
    cout << INT_MIN << endl;
    return 0;
}
