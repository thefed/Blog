// LC 27, rm elements which equal to given val from array
#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>
using namespace std;

void testNumsWithRareVals();
void testNumsWithFreqVals();

int main() {
    cout << "/*\n";
    testNumsWithRareVals();
    testNumsWithFreqVals();
    cout << "*/\n";
}

// note: rare matched items vs frequent matched items? how to minimize num of cmps?
// two pointers: start/end

// two pointers, O(n), check start item and end item each iteration
int removeElement(vector<int>& nums, int val) {
    if (nums.size() == 0)
        return 0;
    int start = 0;
    int end = nums.size() - 1;
    while (start < end) {
        // current element == val, try to grab one item from end
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
        if ((nums[front] != val) && (nums[end] == val)) {
            end--;
            front++;
        } else if ((nums[front] == val) && (nums[end] != val)) {
            swap(nums[front], nums[end]);
            end--;
            front++;
        } else if ((nums[front] != val) && (nums[end] != val)) {
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

// what if the majority items are matched with val?
// mv start index till equal to val, mv end backward till unequal to val
// to avoid redundant comparisons
// con: when nums contain rare target val, sucks for (start < end) checking
int removeElement3(vector<int>& nums, int val) {
    if (nums.size() == 0)
        return 0;
    int start = 0;
    int end = nums.size() - 1;
    while (start < end) {
        while (start < end && nums[start] != val) {
            start++;
        }
        while (start < end && nums[end] == val) {
            end--;
        }
        // here start == val or end != val or start == end
        if (start < end) {
            swap(nums[start], nums[end]);
        }
    }
    return nums[start] == val ? start: start + 1;
}

void runFunc(vector<int>&nums, const int val, const int expected) {
    const int N = 1E3;
    clock_t t = clock();
    assert(removeElement(nums, val) == expected && "wrong output");
    for (int i = 0; i < N; i++)
        removeElement(nums, val);
    cout << "len: " << removeElement(nums, val) << endl;
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

void testNumsWithRareVals() {
    cout << "** testNumsWithRareVals **" << endl;
    const int val = 2;
    const int NUM = 100;
    vector<int> nums(NUM);
    for (int i = 0; i < NUM; i++) {
        nums[i] = i;
    }
    vector<int> nums(array, array + NUM);
    int expected = NUM - 1;
    runFunc(nums, val, expected);
}

void testNumsWithFreqVals() {
    cout << "** testNumsWithFreqVals **" << endl;
    const int val = 2;
    const int NUM = 100;
    vector<int> nums;
    nums.assign(NUM, val);
    int expected = 0;
    runFunc(nums, val, expected);
}

/*
** testNumsWithRareVals **
len: 99
removeElement: 426 ms
removeElement2: 917 ms
removeElement3: 342 ms
** testNumsWithFreqVals **
len: 0
removeElement: 427 ms
removeElement2: 745 ms
removeElement3: 341 ms
*/
