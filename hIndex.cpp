#include<iostream>  // cout
#include<vector>
#include<algorithm> // sort
#include<assert.h>  // assert
using namespace std;
int hIndex(vector<int>& citations) {
    const int len = citations.size();
    vector<int> hash(len + 1, 0);
    for (int i = 0; i < len; i++) {
    	if (citations[i] > len) {
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
	int array[] = {10, 11, 12, 13, 14, 15, 16};
	vector<int> citations(array, array + sizeof(array) / sizeof(int));
	int h = hIndex(citations);
	assert(h == 7 && "h should be 7");

	int array2[] = {3, 0, 6, 1, 5};
	vector<int> citations2(array2, array2 + sizeof(array2) / sizeof(int));
	h = hIndex(citations2);
	assert(h == 3 && "h should be 3");

	int array3[] = {0, 0, 0, 1, 1};
	vector<int> citations3(array3, array3 + sizeof(array3) / sizeof(int));
	h = hIndex(citations3);
	assert(h == 1 && "h should be 1");

	vector<int> citations4(100, 0);
	h = hIndex(citations4);
	assert(h == 0 && "h should be 0");
}
int main() {
	testHIndex();
}
// time complexity: O(N)