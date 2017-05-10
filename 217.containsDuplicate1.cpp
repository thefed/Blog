// LC 217, Given an array of integers, find if the array contains any duplicates
// return true if any value appears twice or more, otherwise falsse
#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_set>
using namespace std;
// use hash table, set::insert(), count(), O(1), worse case(O(N))
bool containsDuplicate(vector<int>& nums) {
	unordered_set<int> set;
	for (int num : nums) {
		if (set.count(num) == 0) set.insert(num);
		else return true;
	}
	return false;
}
int main() {
	vector<int> nums = {1,2,3,4,5,5};	
	assert(containsDuplicate(nums));

	nums.pop_back(); // distinct items
	assert(!containsDuplicate(nums));

	nums.clear();	// empty array => false
	assert(!containsDuplicate(nums));	
	return 0;
}