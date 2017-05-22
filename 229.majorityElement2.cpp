// LC 229, majority element 2
// Given an array of size n, find two majority elements,
// which appear more than ⌊ n/3 ⌋ times.
// assume array is non-empty and the elements exist
#include <iostream> 
#include <cassert>
#include <vector>
#include <unordered_map>
using namespace std;
void print(vector<int>& v, string msg="") {
	cout << msg;
	for (int i : v) printf("%d ", i);
	printf("\n");
}
// method 1: hash table, keep freq
vector<int> majorityElement_hash(vector<int>& nums) {
	vector<int> res;
	unordered_map<int, int> cnts;
	int n = nums.size();
	for (int i : nums) cnts[i]++;

	for (auto it : cnts) if (it.second > n / 3) res.push_back(it.first);
	return res;
}

// Moore Voting Algorithm, faster
vector<int> majorityElement(vector<int>& nums) {
	vector<int> res;
	// maintain two counters for the two candidates
	int cnt1 = 0, cnt2 = 0;
    int candidate1 = -1, candidate2 = -1;
    for (int i = 0; i < nums.size(); i++) {
    	if (nums[i] == candidate1) cnt1++;
    	else if (nums[i] == candidate2) cnt2++;
    	else if (cnt1 == 0) {
    		candidate1 = nums[i];
    		cnt1 = 1;
    	}
    	else if (cnt2 == 0) {
    		candidate2 = nums[i];
    		cnt2 = 1;
    	}
    	else {
    		cnt1--;
    		cnt2--;
    	}
    	printf("n1: %d, n2: %d, c1: %d, c2: %d\n", 
    		candidate1, candidate2, cnt1, cnt2);
    }

    // reset counters, count freq of two candidates
    cnt1 = cnt2 = 0;
    for (int i = 0; i < nums.size(); i++) {
    	if (nums[i] == candidate1) cnt1++;
    	else if (nums[i] == candidate2) cnt2++;
    }

    if (cnt1 > nums.size() / 3) res.push_back(candidate1);
    if (cnt2 > nums.size() / 3) res.push_back(candidate2);
	return res;
}

// sort it... then pick the mid element

void test(vector<int> f(vector<int>&), vector<int>& nums, vector<int>& exp, string msg="") {
	cout << msg;
	vector<int> res = (*f)(nums);
	print(res, "res: ");
	sort(res.begin(), res.end());
	assert(res == exp);
}
int main() {
	vector<int> nums = {1,1,2,2,2,1,3,1,1,2,1};
	vector<int> exp = {1,2};

	test(majorityElement, nums, exp, "moore voting: \n");

	test(majorityElement_hash, nums, exp, "hash: \n");
	return 0;
}
/*
moore voting: 
n1: 1, n2: -1, c1: 1, c2: 0
n1: 1, n2: -1, c1: 2, c2: 0
n1: 1, n2: 2, c1: 2, c2: 1
n1: 1, n2: 2, c1: 2, c2: 2
n1: 1, n2: 2, c1: 2, c2: 3
n1: 1, n2: 2, c1: 3, c2: 3
n1: 1, n2: 2, c1: 2, c2: 2
n1: 1, n2: 2, c1: 3, c2: 2
n1: 1, n2: 2, c1: 4, c2: 2
n1: 1, n2: 2, c1: 4, c2: 3
n1: 1, n2: 2, c1: 5, c2: 3
res: 1 2 
hash: 
res: 2 1 
*/