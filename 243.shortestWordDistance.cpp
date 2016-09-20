#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<climits>	// INT_MAX
#include<stdlib.h>	// abs
#include<unordered_map>
#include<assert.h>
using namespace std;
// Assumptions: both words exist in list, not identical
// Sequential search, time O(N)
int shortestWordDistance(vector<string> &words, string word1, string word2) {
	int index1 = -1;		// index of word1
	int index2 = -1;		// index of word2
	int res = words.size();	// returned distance of words
        // sequential search, O(N), update shortest distance value
	for (int i = 0; i < words.size(); i++) {
		if (words[i] == word1) {
			index1 = i;
			if (index2 != -1) {
				res = min(res, index1 - index2);
			}
		}
		else if (words[i] == word2) {
			index2 = i;
			if (index1 != -1) {
				res = min(res, index2 - index1);
			}
		}
	}
	return res;
}
// follow up: function will be called many times, how to optimize it?
// solution: speed up find with unordered_map, avg. time O(1), worst O(N)
class WordDistance {
private:
	unordered_map<string, vector<int> > wordIndex;
public:
        // initialize map on contruction
	WordDistance(const vector<string> &words) {
		for (int i = 0; i < words.size(); i++) {
			wordIndex[words[i]].push_back(i);
		}
	}

        // use two pointers to find min distance
	int shortest(string word1, string word2) {
		vector<int> indexes1 = wordIndex[word1];
		vector<int> indexes2 = wordIndex[word2];
		int i = 0;
		int j = 0;
		int res = INT_MAX;
		while (i < indexes1.size() && j < indexes2.size()) {
			res = min(res, abs(indexes1[i] - indexes2[j]));
			if (indexes1[i] > indexes2[j]) {
				j++;
			}
			else {
				i++;
			}
		}
		return res;
	}
};
// follow up 2: what if word1 can be the same as word2
int shortestForSameWords(const vector<string> &words, string word) {
	int res = words.size();
	int prevIndex = -1;
	for (int i = 0; i < words.size(); i++) {
		if (words[i] == word) {
			if (prevIndex != -1) {
				res = min(res, i - prevIndex);
				prevIndex = i;
			}
		}
	}
	return res;
}

void testWithClass() {
	char *strArray[] = {"practice", "makes", "perfect", "coding", "makes"};
	vector<string> v(strArray, strArray + 5);
	string word1 = "practice";
	string word2 = "coding";
	WordDistance wd(v);
	int actual = wd.shortest(word1, word2);
	printf("distance: %d\n", actual);
	assert(actual == 3 && "wrong output for test, expected: 3");
	
	word1 = "makes";
	actual = wd.shortest(word1, word2);
	printf("distance: %d\n", actual);
	assert(actual == 1 && "wrong output for test, expected: 1");
	printf("Test with class SUCCESS\n");
}
void test() {
	// initialze string array
	// char *strArray[] = {"a", "n", "d"}; vector<string> v(strArray, strArrray + 3);
	// OR C++ 11: vector<string> v =  {"hi", "world"};
	char *strArray[] = {"practice", "makes", "perfect", "coding", "makes"};
	vector<string> v(strArray, strArray + 5);
	string word1 = "practice";
	string word2 = "coding";
	int actual = shortestWordDistance(v, word1, word2);
	printf("distance: %d\n", actual);
	assert(actual == 3 && "wrong output for test, expected: 3");

	word1 = "makes";
	actual = shortestWordDistance(v, word1, word2);
	printf("distance: %d\n", actual);
	assert(actual == 1 && "wrong output for test, expected: 1");

	// follow up 2
	word2 = "makes";
	if (word1 == word2) {
		actual = shortestForSameWords(v, word1);
	}
	printf("distance: %d\n", actual);
	assert(actual == 1 && "wrong output for test, expected: 3");

	printf("SUCCESS\n");
}
int main() {
	test();
	testWithClass();
}
