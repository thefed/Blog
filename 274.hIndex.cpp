// LC 274, Given an array of citations, [3, 0, 6, 1, 5], return 3
// return h-index, at least h papers have at least h citations

#include <iostream>
#include <vector>
#include <cassert> 
using namespace std;
// hash table
int hIndex(vector<int>& citations) {
	const int len = citations.size();
	vector<int> hash(len + 1, 0);	// hash[i]: the num of papers with i citations
	for (int i = 0; i < len; i++) {
		if (citations[i] > len) hash[len]++;
		else hash[citations[i]]++;
	}
	int h = 0;	// num of papers with citations >= i
	for (int i = len; i >= 0; i--) {
		h += hash[i];
		if (h >= i) return i;
	}
	return 0;
}
int main() {
	vector<int> citations = {3,0,6,1,5};
	int h = hIndex(citations);
	assert(h == 3);

	citations = {10,11,12,13,14,15};
	assert(hIndex(citations) == citations.size());

	citations = {0,0,0,1,1};
	assert(hIndex(citations) == 1);
	return 0;
}