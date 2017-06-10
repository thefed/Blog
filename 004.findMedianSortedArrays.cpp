// LC 4, find median of two sorted arrays, return double
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

// return the kth smallest element in two arrays: nums1[s1, e1) and nums2[s2, e2)
// 1 <= k <= m+n (total length)
int findKth(vector<int> &nums1, int s1, int e1, vector<int> &nums2, int s2, int e2, int k) {
    // ensure array1 is shorter than array2
    if (e1 - s1 > e2 - s2) {
        return findKth(nums2, s2, e2, nums1, s1, e1, k);
    }
    // if the shorter array is empty, return the median of the other one
    if (s1 == e1) {
        return nums2[s2 + k - 1];
    }
    if (k == 1) {
        return min(nums1[s1], nums2[s2]);
    }
    // then array1.size >= 1, k >= 2
    // suppose x elements <= nums1'mid, y elements <= nums2's mid, where x + y = k
    const int x = min(k / 2, e1 - s1);
    const int y = k - x;
    if (nums1[s1 + x - 1] == nums2[s2 + y - 1]) {
        return nums2[s2 + y - 1];
    }
    // else if nums1's mid < nums2's mid, nums[1]=3 < nums2[2]=6
    // [1 3 5], [2 4 6 8 10],k=5,find 5th, x=2,y=3, abandon [1 3], [8 10],
    // then find 3rd, since [1 3] must be among the 5 smallest elements
    else if (nums1[s1 + x - 1] < nums2[s2 + y - 1]) {
        return findKth(nums1, s1 + x, e1, nums2, s2, s2 + y, y);
        // findKth(nums1, 2, 3, nums2, 0, 3, 3); [5] [2 4 6]
        // k=3,new x=1,y=2, nums1[0]=5 > nums2[1]=4
        // findKth(nums1, 2, 3, nums2, 2, 3, 1); => find min in [5], [6]
    }
    else {  // cut array2's left half and array1's right half
        return findKth(nums1, s1, s1 + x, nums2, s2 + y, e2, x);
    }
}

// return k-th smallest item in two sorted subarrays: nums1[s1, e1), nums2[s2, e2)
// 1 <= k <= m + n (m: nums1.size, n: nums2.size)
int findKth2(vector<int>& nums1, int s1, int e1, vector<int>& nums2, int s2, int e2, int k) {
    // ensure array 1 is shorter,
    if (e1 - s1 > e2 - s2) {
        return findKth2(nums2, s2, e2, nums1, s1, e1, k);
    }
    // shorter array is empty, return k-th of the other one
    if (s1 == e1) {
        return nums2[s2 + k - 1];
    }
    if (k == 1) {
        return min(nums1[s1], nums2[s2]);
    }
    // then k >= 2, m, n >= 1

    int x = min(k / 2, e1 - s1);
    int y = k - x;
    // ideally, assume k/2 items in array1, k/2 items in array2
    if (nums1[s1 + x - 1] == nums2[s2 + y - 1]) {
        return nums1[s1 + x - 1];
    }
    // at least x + y = k items <= nums2[s2 + y - 1]
    // found x smaller items, drop them
    else if (nums1[s1 + x - 1] < nums2[s2 + y - 1]) {
        return findKth(nums1, s1 + x, e1, nums2, s2, e2, y);
    }
    // found y smaller items, drop them
    else {
        return findKth(nums1, s1, e1, nums2, s2 + y, e2, x);
    }
}

// T(m+n, k) = T(m+n - k/2, k/2) + O(1), where k = (m+n)/2
// time T: O(log(m + n))
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    // if the total number of elements is odd
    const int N1 = nums1.size();
    const int N2 = nums2.size();
    const int k = (N1 + N2) / 2;
    double median1 = findKth(nums1, 0, N1, nums2, 0, N2, k + 1);
    if ((N1 + N2) % 2 == 1) {
        return median1;
    }
    else {
        return (findKth(nums1, 0, N1, nums2, 0, N2, k) + median1) / 2.0;
    }
}

void test_findKth() {
    vector<int> nums1 = {1, 3, 5}, nums2 = {2, 4, 6, 8, 10};
    vector<int> exp = {1,2,3,4,5,6,8,10};
    int totalLen = nums1.size() + nums2.size();
    for (int i = 0; i < totalLen; i++) {
        int res = findKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), i + 1);
        printf("test %d, find %d-th, res: %d\n", i + 1, i + 1, res);
        assert(res == exp[i]);
    }
}
int main() {
    test_findKth();
    
    vector<int> nums1 = {1, 3, 5}, nums2 = {2, 4, 6, 8, 10};
    // {1,2,3,4,5,6,8,10}, median = 5
    double median = findMedianSortedArrays(nums1, nums2);
    assert(median == 4.5);

    double median2 = findMedianSortedArrays(nums2, nums1);
    assert(median2 == 4.5);

    nums1 = {};
    assert(findMedianSortedArrays(nums1, nums2) == 6);
    return 0;
}
