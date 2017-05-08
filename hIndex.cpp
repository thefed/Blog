#include<iostream>  // cout
#include<vector>
#include<algorithm> // sort
#include<cassert>   // assert
using namespace std;

// return the h-index of a list of citations, 
// at least h papers have citations >= h
// time complexity: O(N)
int hIndex(vector<int>& citations) {
    const int len = citations.size();
    vector<int> hash(len + 1, 0);
    for (int i = 0; i < len; i++) {
    	if (citations[i] > len) {  // citation > max_h, count it as max_h
    		hash[len]++;
    	}
    	else {
    		hash[citations[i]]++;
    	}
    }
    int h = 0;
    for (int i = len; i >= 0; i--) {
    	h += hash[i];	// num of papers with citations >= i
    	if (h >= i)
    		return i;
    }
    return 0;
}
void testHIndex() {
	vector<int> citations = {10, 11, 12, 13, 14, 15, 16};
	int h = hIndex(citations);
	assert(h == 7);

	vector<int> citations2 = {3, 0, 6, 1, 5};
	h = hIndex(citations2);
	assert(h == 3);

	vector<int> citations3 = {0, 0, 0, 1, 1};
	h = hIndex(citations3);
	assert(h == 1);

	vector<int> citations4(100, 0);
	h = hIndex(citations4);
	assert(h == 0);
}
int main() {
	testHIndex();
}