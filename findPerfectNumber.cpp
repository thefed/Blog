#include<iostream>
#include<math.h>
using namespace std;
bool isPerfectNumber(int x) {
    if (x <= 1) return false;
    int root = sqrt(x);
    int sum = 1;
    for (int i = 2; i <= root; i++) {
        if (x % i == 0 && i * i != x) {
            sum += i + x / i;
        }
    }
    return sum == x;
}
int main() {
    const int N =  1E6;
    for (int i = 1; i <= N; i ++) {
        if (isPerfectNumber(i)) {
            cout << "Perfect number: " << i << endl;
        }
    }
    return 0;
}
