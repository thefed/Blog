// LC 60, get k-th permutation of [1..n]
// 123, 132, 213, 231, 312, 321
// k=3 => 213
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// based on factorials array, decide one digit at a time
// [1234], k=12, ([11])
// 1xxx, 2xxx, 3xxx, 4xxx (6 results each)
// 21xx, 23xx, 24xx
// 241x, 243x
// 2431
string getPermutation(int n, int k) {
	if (n == 1) return "1";
	vector<int> factorials(n, 1);	// [1,2,6,24],n=4
	for (int i = 2; i <= n; i++) {
		factorials[i - 1] = i * factorials[i - 2];
	}	
	vector<int> nums(n);	// [1..4]
	for (int i = 1; i <= n; i++) nums[i - 1] = i;

	string res;
	k--;				//k=11
	int i = n - 2;		// last digit to cmp
	while (i >= 0) {
		int id = k / factorials[i];	// [1], [2]
		res += to_string(nums[id]);	// "2" + "4" +"3"
		nums.erase(nums.begin() + id);	// rm 2 from [1234] => [134] =>[13] => [1]
		k %= factorials[i];			// [5], [1], [0]
		i--;	// 1, 0
	}
	res += to_string(nums[0]);
	return res;
}
int main() {
	int n = 3;
	int k = 3;	
	string res = getPermutation(n, k);
	cout << res << endl;
	assert(res == "213");

	vector<string> exp = {"123","132","213","231","312","321"};
	for (int i = 1; i <= 6; i++) {
		res = getPermutation(n, i);
		cout << res << endl;
		assert(res == exp[i - 1]);
	}
	return 0;
}