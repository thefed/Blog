#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;
bool canJumpUpToLength(const vector<int> &nums, int startIdx, int target, vector<bool> &failedIndices) {

    if (target == 0) {  // distance to the last element
        return true;
    }
 	// already reach the last second elment, failed
    else if (startIdx >= nums.size() - 1 || nums[startIdx] == 0) {
        return false;
    }
    if (failedIndices[startIdx])	return false;
    // printf("maxStep: %d, startIdx: %d, target: %d\n", nums[startIdx], startIdx, target);
    int j = min(nums[startIdx], int(nums.size() - 1 - startIdx));
	for (; j >= 1; j--) {
        if (canJumpUpToLength(nums, startIdx + j, target - j, failedIndices)) {
            return true;
        }
    }
    // printf("Tried all step size for [%d]\n", startIdx);
    failedIndices[startIdx] = true;
    return false;
}
bool canJump(vector<int>& nums) {
    // target numbers of jump: nums.size() - 1
    // at each step: jump range: 1 to currNum
    if (nums.empty()) return false;
    else if (nums.size() == 1) return true;
    vector<bool> failedIndices(nums.size(), false);
    return canJumpUpToLength(nums, 0, nums.size() - 1, failedIndices);
}
void testWith(int arr[], const int len, bool expected) {
	vector<int> nums(arr, arr + len);
	bool actual = canJump(nums);
	printf("actual = %d\n", actual);
	assert(actual == expected && "wrong output");
	printf("SUCCESS\n");
}
void test() {
	int arr1[] = {2,3,1,1,4};
	int arr2[] = {3,2,1,0,4};
	int arr3[] = {1, 2};
	int arr4[] = {0, 2, 3};
	int arr5[] = {2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
	int arr6[] = {2,4,4,2,0,3,1,4,1,3,2,0,1,1,2,1,0,1,4};
	int arr7[] = {4,3,2,1,1,0,0};
	// create large array, time limit exceeded!
	const int N = 25000;
	int arr8[N + 3];
	for (int i = 0; i < N; i++) {
		arr8[i] = N - i;
	}
	arr8[N] = 1;
	arr8[N + 1] = 0;
	arr8[N + 2] = 0;
	// testWith(arr1, sizeof(arr1) / sizeof(int), true);
	// testWith(arr2, sizeof(arr2) / sizeof(int), false);
	// testWith(arr3, sizeof(arr3) / sizeof(int), true);
	// testWith(arr4, sizeof(arr4) / sizeof(int), false);
	// testWith(arr5, sizeof(arr5) / sizeof(int), false);
	// testWith(arr6, sizeof(arr6) / sizeof(int), false);
	// testWith(arr7, sizeof(arr7) / sizeof(int), false);
	testWith(arr8, sizeof(arr8) / sizeof(int), false);
}
int main() {
	test();
}