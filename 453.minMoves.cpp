// LC 453, Given a non-empty integer array of size n, 
// find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
// [1,2,3] => 3
// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

// follow up: a move can either increment or decrement n - 1 items, find min num of moves to make all equal
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int partition(vector<int>& nums, int low, int high) {
    int pivot_id = high;
    int pivot = nums[pivot_id];
    int j = low;    // start index of element that is < pivot
    for (int i = low; i < high; i++) {
        // mv larger items to the left
        if (nums[i] >= pivot) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
    // finally, place pivot back to its position
    swap(nums[j], nums[pivot_id]);
    return j;
}

// time: T(n) = T(n/2) + O(n), at most n swaps => O(n),
int findKthLargest(vector<int>& nums, int k) {
    int low = 0, high = nums.size() - 1;
    while (true) {
        int pivot_id = partition(nums, low, high);
        if (pivot_id == k - 1) return nums[pivot_id];
        else if (pivot_id < k - 1) low = pivot_id + 1;  // update low, continue to partition [low, high]
        else high = pivot_id - 1;   // narraw high, [low, pivot_id - 1]
    }
}

// follow up: a move can either increment or decrement n - 1 items, find min num of moves to make all equal
// let target val = x, goal becomes find x such that sum over i:|nums[i] - x| is mininized (abs)
// when size (n) is odd, x should be median, nums[n - 1 - k] - x + x - nums[k]; when n is even, x is still median
// problems becomes finding medain of an unsorted array
// method 1: sort it, take nums[mid], O(nlogn)
// method 2: use quick sort, find pivot, O(n)
int minMoves2(vector<int>& nums) {
    int mid = (nums.size() + 1) / 2;
    int median = findKthLargest(nums, mid);
    printf("median: %d\n", median);
    int mv = 0; // min moves needed
    for (int num : nums) mv += abs(num - median);
    return mv;
}

// increase n-1 elementss is equavalent to decrease one element
int minMoves(vector<int>& nums) {
	int mv = 0;		// num of moves needed
	int minVal = nums[0];
	// find min
	for (int n : nums) minVal = min(minVal, n);

	// calc total mv
	for (int n : nums) mv += (n - minVal);
	return mv;
}
int main() {
	vector<int> nums = {1,2,4,5,6};
	assert(minMoves(nums) == 13);

	nums = {6,5,4,2,1};
	assert(minMoves(nums) == 13);

	nums = {1,2,3};
	assert(minMoves(nums) == 3);

    // test minMoves2
    assert(minMoves2(nums) == 2);
    
	nums = {6,5,4,2,1};
    assert(minMoves2(nums) == 8);  // median 4, mv=2+1+2+3
	return 0;
}
