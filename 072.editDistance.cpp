// LC 72, Given two words word1 and word2,
//  find the minimum number of steps required to convert word1 to word2. 
// (each operation is counted as 1 step.)
//3 operations permitted on a word:
// a) Insert a character
// b) Delete a character
// c) Replace a character
#include <iostream>
#include <string>
#include <cassert>
#include <vector>
using namespace std;
// dp
int minDistance(string word1, string word2) {

}
int main() {
	assert(minDistance("abc", "abc") == 0);

	assert(minDistance("abc", "") == 3);

	assert(minDistance("abc", "ba") == 3);	// r, r, d

	assert(minDistance("abc", "abef") == 2);	// replace + insert
	return 0;
}