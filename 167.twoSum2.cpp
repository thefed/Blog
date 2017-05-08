#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;
// return one-based index, given sorted array, use two pointers
vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> res;
    for (int i = 0; i < numbers.size() - 1; i++) {
        int goal = target - numbers[i];
        // search from i + 1 to last one
        int left = i + 1;
        int right = numbers.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (numbers[mid] < goal) {
                left = mid + 1;
            }
            else if (numbers[mid] > goal) {
                right = mid - 1;
            }
            else {
                res.push_back(i + 1);
                res.push_back(mid + 1);
                return res;
            }
        }
        if (left != i && (numbers[left] == goal || numbers[right] == goal)) {
            res.push_back(i + 1);
            res.push_back(numbers[left] == goal ? left + 1: right + 1);
            return res;
        }
    }
    return res;
}
void test() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> actual = twoSum(numbers, target);
    assert(actual.size() == 2 && "wront output size");
    cout << actual[0] << ", " << actual[1] << endl;
    assert(actual[0] == 1 && actual[1] == 2 && "wrong output");
    assert(actual == (vector<int> {1, 2}));
}
int main() {
    test();
}
