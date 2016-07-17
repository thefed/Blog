#include<iostream>  // cout
#include<vector>    // vector
#include<assert.h>  // assert
#include<time.h>    // clock
using namespace std;

// two pointers
int removeElement(vector<int>& nums, int val) {
    if (nums.size() == 0)
        return 0;
    int start = 0;
    int end = nums.size() - 1;
    while (start < end) {
        // current element == val, right pointer != val
        if (nums[start] == val) {
            if (nums[end] != val) {
                swap(nums[start], nums[end]);
                start++;
            }
            end--;
        }           
        else {
            start++;
            if (nums[end] == val) {
                end--;
            }
        }
    }
    return nums[start] == val ? start: start + 1; 
}

int removeElement2(vector<int>& nums, int val) {
    if (nums.size() == 0) return 0;
    int front = 0;
    int end = nums.size()-1;
    while (front <= end){
        if ((nums[front] - val != 0) && (nums[end] - val == 0)) {
            end--;
            front++;
        } else if ((nums[front] - val == 0) && (nums[end] - val != 0)) {
            swap(nums[front], nums[end]);
            end--;
            front++;
        } else if ((nums[front] - val != 0) && (nums[end] - val != 0)) {
            front++;
        } else {
            end--;
        }
    }
    if (nums[end] - val == 0) {
        end--;
    }
    return end + 1;
}

// avoid redundant comparisons, con: when nums contain rare target val, sucks for (start < end) checking
int removeElement3(vector<int>& nums, int val) {
    if (nums.size() == 0)
        return 0;
    int start = 0;
    int end = nums.size() - 1;
    while (start < end) {
        while (nums[start] != val && start < end) {
            start++;
        }
        while (nums[end] == val && end > start) {
            end--;
        }
        // here start == val or end != val or start == end
        if (start < end) {
            swap(nums[start], nums[end]);
        }
    }
    return nums[start] == val ? start: start + 1; 
}

void testNumsWithRareVals() {
    cout << "** testNumsWithRareVals **" << endl;
    int val = 2;
    const int NUM = 100;
    int* array = new int[NUM];
    for (int i = 0; i < NUM; i++) {
        *(array + i) = i;
    }
    vector<int> nums(array, array + NUM);
    const int expected = NUM - 1;
    const int N = 1E3;
    clock_t t = clock();
    assert(removeElement(nums, val) == expected && "wrong output");
    for (int i = 0; i < N; i++)
        removeElement(nums, val);
    cout << removeElement(nums, val) << endl;
    cout << "removeElement: " << clock() - t << " ms\n";

    t = clock();    
    assert(removeElement2(nums, val) == expected);
    for (int i = 0; i < N; i++)
        removeElement2(nums, val); 
    cout << "removeElement2: " << clock() - t << " ms\n";

    t = clock();
    assert(removeElement3(nums, val) == expected);
    for (int i = 0; i < N; i++)
        removeElement3(nums, val);
    cout << "removeElement3: " << clock() - t << " ms\n";
    delete [] array;
}

void testNumsWithFreqVals() {
    cout << "** testNumsWithFreqVals **" << endl;
    int val = 2;
    // int array[8] = {1, 2, 2, 3, 5, 6, 2, 2};
    const int NUM = 100;
    vector<int> nums;
    nums.assign(NUM, val);
    const int expected = 0;
    const int N = 1E3;
    clock_t t = clock();
    assert(removeElement(nums, val) == expected && "wrong output");
    for (int i = 0; i < N; i++)
        removeElement(nums, val);
    cout << removeElement(nums, val) << endl;
    cout << "removeElement: " << clock() - t << " ms\n";

    t = clock();    
    assert(removeElement2(nums, val) == expected);
    for (int i = 0; i < N; i++)
        removeElement2(nums, val); 
    cout << "removeElement2: " << clock() - t << " ms\n";

    t = clock();
    assert(removeElement3(nums, val) == expected);
    for (int i = 0; i < N; i++)
        removeElement3(nums, val);
    cout << "removeElement3: " << clock() - t << " ms\n";
}

int main() {
    testNumsWithRareVals();
    testNumsWithFreqVals();
}
