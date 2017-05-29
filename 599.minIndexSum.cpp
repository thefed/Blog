// LC 599, min index sum of two string arrays
// given two string arrays, find matching pairs and return the pairs with the min index sum
// {"Shogun", "Tapioca Express", "Burger King", "KFC"}
// {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"}
// output: {"shogun"}

// no dup in array, 0-based index, array length: 1~1000, string item length: 1~30

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cassert>
using namespace std;
void print(vector<string>& strs, string msg="") {
	cout << msg;
	for (string& s : strs) cout << s << " ";
	cout << endl;	
}
// or use bucket sort

// time: O(max(m, n))
vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
	vector<string> res;
	int minSum = INT_MAX;
	unordered_map<string, int> map;
	for (int i = 0; i < list2.size(); i++) map[list2[i]] = i;

	for (int i = 0; i < list1.size(); i++) {
		if (map.find(list1[i]) != map.end()) {
			int j = map[list1[i]];
			if (i + j <= minSum) {
				if (i + j < minSum) {
					res.clear(); 
					minSum = i + j;
				}
				res.push_back(list1[i]);
			}
		}
	}
	return res;
}
int main() {
	vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
	vector<string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
	vector<string> res = findRestaurant(list1, list2);
	vector<string> exp = {"Shogun"};
	print(res, "res: ");
	print(exp, "exp: ");
	assert(res == exp);

	list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
	list2 = {"KFC", "Shogun", "Burger King"};
	res = findRestaurant(list1, list2);
	print(res, "res: ");
	assert(res == exp);
}