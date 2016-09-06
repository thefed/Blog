#include<iostream>
#include<vector>
#include<algorithm> // max
#include<assert.h>
using namespace std;
void printVec(const vector<int> &v, string msg = "") {
    cout << msg << " ";
    cout << "size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        // if (i >= 1 && v[i] < v[i - 1]) break;
        cout << v[i] << " ";
    }
    cout << endl;
}
int wiggleMaxLength(vector<int> &nums) {
    /*  1,17,5,10,13,15,10,5,16,8
    Up: 1 2 2  4  4  4  4  6 6  6
  Down: 1 1 3  3  3  3  5  5 5  7
    */
    if (nums.size() <= 1) {
        return nums.size();
    }
    // up: the length of longest wiggle seq considering the first i elements of array
    vector<int> maxLensEndsWithUp(nums.size(), 1);
    vector<int> maxLensEndsWithDown(nums.size(), 1);
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            maxLensEndsWithDown[i] = maxLensEndsWithDown[i - 1];
            maxLensEndsWithUp[i] = maxLensEndsWithUp[i - 1];
        }
        // if using current el, then it is an up wiggle, update based on last down wiggle
        else if (nums[i] > nums[i - 1]) {
            maxLensEndsWithUp[i] = maxLensEndsWithDown[i - 1] + 1;
            maxLensEndsWithDown[i] = maxLensEndsWithDown[i - 1];
        }
        // current wiggle is a down wiggle, if using it, update based on last up wiggle
        else { 
            maxLensEndsWithDown[i] = maxLensEndsWithUp[i - 1] + 1;
            maxLensEndsWithUp[i] = maxLensEndsWithUp[i - 1];
        }
    }
    // printVec(maxLensEndsWithDown, "downArr");
    return max(maxLensEndsWithUp[nums.size() - 1], maxLensEndsWithDown[nums.size() - 1]);
}
void testWithData(int arr1[], int len, int expected) {
    // vector<int> nums1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> nums1(arr1, arr1 + len);
    int actual = wiggleMaxLength(nums1);
    printf("actual = %d\n", actual);
    assert(actual == expected && "wrong output for test case 1");
    printf("SUCCESS\n\n");
}
void test() {
    int arr1[] = {1,7,4,9,2,5};
    // vector<int> nums1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    // int actual = wiggleMaxLength(nums1);
    // printf("actual = %d\n", actual);
    // assert(actual == 6 && "wrong output for test case 1");

    int arr2[] = {1,17,5,10,13,15,10,5,16,8};
    // vector<int> nums2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    // actual = wiggleMaxLength(nums2);
    //  printf("actual = %d\n", actual);
    // assert(actual == 7 && "wrong output for test case 2");

    int arr3[] = {1,2,3,4,5,6,7,8,9};
    // vector<int> nums3(arr3, arr3 + sizeof(arr3) / sizeof(int));
    // actual = wiggleMaxLength(nums3);
    // printf("actual = %d\n", actual);
    // assert(actual == 2 && "wrong output for test case 3");
    // printf("SUCCESS\n");

    int arr4[] = {33,53,12,64,50,41,45,21,97,35,47,92,39,0,93,55,40,46,69,42,6,95,51,68,72,9,32,84,34,64,6,2,26,98,3,43,30,60,3,68,82,9,97,19,27,98,99,4,30,96,37,9,78,43,64,4,65,30,84,90,87,64,18,50,60,1,40,32,48,50,76,100,57,29,63,53,46,57,93,98,42,80,82,9,41,55,69,84,82,79,30,79,18,97,67,23,52,38,74,15};
    testWithData(arr1, sizeof(arr1) / sizeof(int), 6);
    testWithData(arr2, sizeof(arr2) / sizeof(int), 7);
    testWithData(arr3, sizeof(arr3) / sizeof(int), 2);
    testWithData(arr4, sizeof(arr4) / sizeof(int), 67);
}
int main() {
    test();
}