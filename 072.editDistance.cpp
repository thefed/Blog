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
	// dp[i][j]: min num of operations to get s2[0..j-1] from s1[0...i-1], 
	// boundary case: i = 0; or j=0
	// dp[i][0] (j=0) means to empty str, need rm i times

	int m = word1.size(), n = word2.size();
	vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
	for (int i = 1; i <= m; i++) dp[i][0] = i;
	for (int j = 1; j <= n; j++) dp[0][j] = j;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else {
				dp[i][j] = min(
					dp[i - 1][j - 1] + 1, // replace w1[i-1]
					min(dp[i - 1][j] + 1,	// delete w1[i-1]
					dp[i][j - 1] + 1) // insert w2[j-1]
					);
			}
		}
	}
	return dp[m][n];
}
int main() {
	assert(minDistance("abc", "abc") == 0);

	assert(minDistance("abc", "") == 3);

	assert(minDistance("abc", "ba") == 2);	// rm 'a', replace 'c'

	assert(minDistance("abc", "abef") == 2);	// replace + insert

	assert(minDistance("abef", "abc") == 2);	// replace + insert
	return 0;
}