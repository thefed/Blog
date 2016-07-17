#include<iostream>  // cout
#include<algorithm> // swap
#include<time.h>    // clock
#include<assert.h>  // assert
using namespace std;

// performance
// xorSwap(): 785 ms
// addSwap(): 750 ms
// swap(): 433 ms
// conclusion: template swap recommended

// slower than template swap
void xorSwap(int& a, int& b){
    if (a != b) {   // fails when a = b, resulting 0
         a = a ^ b;  
        b = b ^ a;  // b ^ (a ^ b) = a
        a = a ^ b;  // (a ^ b) ^ (a)   
    }
}

// also slower than template swap
void addSwap(int& x, int& y) {
    if (x != y) {
        x = x + y;  // prone to integer overflow error
        y = x - y;  // (x + y - y)
        x = x - y;  // (x + y) - x
    }
}

int main() {
    int x = 10;
    int y = 20;
    int N = 1E5;
    clock_t t = clock();
    for (int i = 0; i < N; i++) {
        xorSwap(x, y);
    }
    cout << "xorSwap(): " << clock() - t << " ms\n";
    assert(x == 10 && y == 20);

    t = clock();
    for (int i = 0; i < N; i++) {
        addSwap(x, y);
    }
    cout << "addSwap(): " << clock() - t << " ms\n";
    // assert(x == 10 && y == 20);

    t = clock();
    for (int i = 0; i < N; i++) {
     swap(x, y);
    }
     cout << "swap(): " << clock() - t << " ms\n";
    assert(x == 10 && y == 20);
    return 0;
}
