#include<iostream>
#include<vector>
#include<unordered_map>
#include<assert.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> res;
	unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); i++) {
		if (m.find(target - nums[i]) != m.end()) {
			res.push_back(i);
			res.push_back(m[target - nums[i]]);
			return res;
		}
		m[nums[i]] = i; 	// key: nums[i], val: index i
	}
	return res;
}
void testTwoSum() {
	int array[] = {12, 2, 2, 12};	// create vector from array
	vector<int> nums(array, array + sizeof(array) / sizeof(int));
	int target = 4;
	vector<int> res = twoSum(nums, target);
	printf("Ret index: %d, %d\n", res[0], res[1]);
	assert(res.size() == 2 && nums[res[0]] + nums[res[1]] == target && "wrong output");

	int array2[] = {12, 2, 4, 12};
	vector<int> nums2(array2, array2 + sizeof(array2) / sizeof(int));
	target = 14;
	res = twoSum(nums2, target);
	printf("Ret index: %d, %d\n", res[0], res[1]);
	assert(res.size() == 2 && nums2[res[0]] + nums2[res[1]] == target && "wrong output");
	cout << "SUCCESS\n";
}
int main() {
	testTwoSum();
	return 0;
}
