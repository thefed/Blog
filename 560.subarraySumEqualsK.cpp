// LC 560, find the num of continuous subarrays with sum == k
// k=4
// in  [1,2,-2,3,1,0,1,1]
// sum  1 3  1 4 5 5 6 7
// map  1 3  
// cnt  0 
#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>
using namespace std;
int subarraySum(vector<int>& nums, int k) {
	int sum = 0;
	int cnt = 0;
	unordered_map<int, int> map;	// {key=sum till i, val=cnt of sum}
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if (sum == k) cnt++; // from [0, i]
		if (map.find(sum - k) != map.end()) {
			cnt += map[sum - k];
		}

		// add this sum to map
		map[sum]++;
	}
	return cnt;
}
int main() {
	vector<int> nums = {1,2,-2,3,1,0,1,1};
	int k = 4;
	int res = subarraySum(nums, k);
	// exp=1+2+2+1
	int exp = 6;	// [1,2,-2,3], [2,-2,3,1], [3,1], [2,-2,3,1,0],[2..1],[-2..1]
	printf("res = %d\n", res);

	assert(res == exp);
	return 0;
}