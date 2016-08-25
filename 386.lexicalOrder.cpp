#include<iostream>
#include<vector>
#include<algorithm>
#include<assert.h>
using namespace std;
void print(const vector<int> & vec) {
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << ", ";
  }
  cout << endl;
}
vector<int> lexicalOrder(int n) {
    vector<int> res;
    int curr = 1;
    for (int i = 1; i <= n; i++) {
      res.push_back(curr);
      if (curr * 10 <= n) {
        curr *= 10; // 1, 10, 100...
      }
      else if (curr % 10 != 9 && curr <= n - 1) {
        curr++;     // n = 35, curr = 34
      }
      else {  // get first digit of current number
        // n = 323, curr = 299, next = 3
        // n = 13, curr = 13, next = 2
        while ((curr / 10) % 10 == 9) {
          curr /= 10;
        }
        curr = curr / 10 + 1;
      }
    }
    return res;
}
void testLexicalOrder() {
  int n = 1; 
  vector<int> actual = lexicalOrder(n);
  assert(actual.size() == n && "n = 1, wrong output");

  n = 0;
  actual = lexicalOrder(n);
  assert(actual.size() == n && "n = 0, wrong output");

  n = 13;
  actual = lexicalOrder(n);
  assert(actual.size() == n && "n = 13, wrong output size");
  int arr[13] = {1,10,11,12,13,2,3,4,5,6,7,8,9};
  for (int i = 0; i < actual.size(); i++) {
    assert(actual[i] == arr[i] && "n = 13, wrong output");
  }

  n = 100;
  actual = lexicalOrder(n);
  int arr2[100] = {1,10,100,11,12,13,14,15,16,17,18,19,2,20,21,22,23,24,25,26,27,28,29,3,30,31,32,33,34,35,36,37,38,39,4,40,41,42,43,44,45,46,47,48,49,5,50,51,52,53,54,55,56,57,58,59,6,60,61,62,63,64,65,66,67,68,69,7,70,71,72,73,74,75,76,77,78,79,8,80,81,82,83,84,85,86,87,88,89,9,90,91,92,93,94,95,96,97,98,99};
  assert(actual.size() == n && "n = 100, wrong output size");
  print(actual);
  for (int i = 0; i < actual.size(); i++) {
    if (actual[i] != arr2[i]) {
      printf("[%d] = %d, exp = %d", i, actual[i], arr2[i]);
    }
    assert(actual[i] == arr2[i] && "n = 100, wrong output");
  }
}
int main() {
  testLexicalOrder();
}