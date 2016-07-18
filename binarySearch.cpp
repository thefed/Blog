#include<iostream>  // cout
#include<vector>    // vector
#include<algorithm> // sort
#include<assert.h>  // assert
using namespace std;

const int N = 100;
// binary search, find the first position of target, return -1 if not exist
int binarySearch(vector<int>& nums, int target);
void runFunc(vector<int>& nums, int target, const int expected);
void testBSWithInexistentTarget();
void testBSWoDuplicates();
void testBSWithDistinctNums();

int main() {
    cout << "/*\n";
    testBSWithInexistentTarget();
    testBSWoDuplicates();
    testBSWithDistinctNums();
    cout << "*/\n";
}

int binarySearch(vector<int>& nums, int target){
    if (nums.size() == 0)
        return -1;
    int start = 0;
    int end = nums.size() - 1;
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] < target) {
           start = mid;
        }
        else if (nums[mid] == target) {
            end = mid;
        } 
        else {
            end = mid;
        }
    }
    if (nums[start] == target)
        return start;
    if (nums[end] == target) 
        return end;
    return -1;
}

void runFunc(vector<int>& nums, int target, const int expected) {
    int actual = binarySearch(nums, target);
    assert(actual == expected && "wrong output");
}

void testBSWithInexistentTarget() {
    cout << "** testBSWithInexistentTarget **\n";
    int *array = new int[N];
    for (int i = 0; i < N; i++)
        *(array + i) = 2 * i + 1;
    vector<int> nums(array, array + N);
    delete array;
    const int target = -1;
    const int expected = -1;
    runFunc(nums, target, expected);
}

void testBSWoDuplicates() {
    cout << "** testBSWoDuplicates **\n";
    int *array = new int[N];
    for (int i = 0; i < N; i++)
        *(array + i) = i / 2;
    vector<int> nums(array, array + N);
    delete array;
    const int target = 10;
    const int expected = 20;
    runFunc(nums, target, expected);
}

void testBSWithDistinctNums() {
    cout << "** testBSWithDistinctNums **\n";
    int *array = new int[N];
    for (int i = 0; i < N; i++)
        *(array + i) = i;
    vector<int> nums(array, array + N);
    delete array;
    const int target = N/2;
    const int expected = N/2;
    runFunc(nums, target, expected);
}
