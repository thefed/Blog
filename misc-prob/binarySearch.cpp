#include <iostream> 
#include <vector>  
#include <algorithm> // sort
#include <assert.h> 
#include <string> 
using namespace std;

const int N = 100;
// binary search, find the first position of target, return -1 if not exist
int binarySearch(vector<int>& nums, int target);
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
    if (nums.empty()) return -1;
    int start = 0;
    int end = nums.size() - 1;
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] < target) {
           start = mid;
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

// test target function, with given input
void test(int f(vector<int>&, int), vector<int>& nums, int target, int exp, string msg="") {
    cout << msg;
    int res = (*f)(nums, target);
    printf("%d\n", res);
    assert(res == exp);
}

void testBSWithInexistentTarget() {
    vector<int> nums(N);    // 1,3,5...
    for (int i = 0; i < N; i++) nums[i] = 2*i + 1;
    const int target = -1;
    const int expected = -1;
    test(binarySearch, nums, target, expected, "search inexistent item: \n");
}

void testBSWoDuplicates() {
    vector<int> nums(N);    // 0,0,1,1,2,2...
    for (int i = 0; i < N; i++) nums[i] = i / 2;
    const int target = 10;
    const int expected = 20;
    test(binarySearch, nums, target, expected, "array with duplicates: \n");

    vector<int> nums2(N, target);
    test(binarySearch, nums2, target, 0, "array with duplicates: \n");
}

void testBSWithDistinctNums() {
    vector<int> nums(N);
    for (int i = 0; i < N; i++) nums[i] = i;
    const int target = N/2;
    const int expected = N/2;
    test(binarySearch, nums, target, expected, "array has no duplicates: \n");
}
/*
search inexistent item: 
-1
array with duplicates: 
20
array with duplicates: 
0
array has no duplicates: 
50
*/
