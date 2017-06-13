#include <iostream>
#include <cmath>
using namespace std;
// perfect number: if the sum of n's factors equal to n itself, it is a perfect number
// e.g. 6 = 1 + 2 + 3; 28 = 1 + 2 + 4 + 7 + 14
// find out all perfect numbers in [1, 100000]
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
    printf("/* perfect numbers in [1, %d]: ", N);
    for (int i = 1; i <= N; i ++) {
        if (isPerfectNumber(i)) {
            printf("%d, ", i);
        }
    }
    printf(" */\n");
    return 0;
}
/* perfect numbers in [1, 100000]: 6, 28, 496, 8128,  */
