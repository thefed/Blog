// LC 275, what if citations array is sorted in ascending order? how to optimize?
// return h-index, at least h papers have at least h citations

#include <iostream>
#include <vector>
#include <cassert> 
using namespace std;
// sorted citations input, binary search
int hIndex(vector<int>& citations) {
	// h-index is in [0..len]
	int low = 0, high = citations.size() - 1, mid;
	int len = citations.size();
	while (low <= high) {
		mid = low + (high - low) / 2;	
		if (citations[mid] == len - mid) return citations[mid];
		else if (citations[mid] > len - mid) high = mid - 1;
		else low = mid + 1;
		// printf("l: %d, m: %d, h: %d\n", low, mid, high);
	}
	return len - low;
}
int main() {
	vector<int> citations = {0,1,3,4,5,6};
	int h = hIndex(citations);
	assert(h == 3);

	citations = {10,11,12,13,14,15};
	assert(hIndex(citations) == citations.size());

	citations = {0,0,0,1,1};
	assert(hIndex(citations) == 1);

	citations = {0};
	assert(hIndex(citations) == 0);

	citations = {2};
	assert(hIndex(citations) == 1);
	return 0;
}