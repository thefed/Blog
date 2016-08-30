#include<iostream>
#include<vector>
#include<unordered_map>
#include<assert.h>
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> table;
    for (int i = 0; i < nums.size(); i++) {
        unordered_map<int, int>::iterator iter = table.find(nums[i]);
        if (iter != table.end() && i - iter->second <= k) {
            return true;
        }
        table[nums[i]] = i;
    }
    return false;
}
void test() {
	int array[] = {1, 2, 3, 4, 5, 3};
	vector<int> nums(array, array + sizeof(array) / sizeof(int));
	int k = 3;
	bool actual = containsNearbyDuplicate(nums, k);
	assert(actual == true && "wrong output");

	k = 2;
	actual = containsNearbyDuplicate(nums, k);
	assert(actual == false && "wrong output");
}
int main() {
	test();
}