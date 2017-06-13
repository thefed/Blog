// LC 30, find substrs which are concatenations of all words of the given list
// words in the list have the same length
// each word should appear once in the substr
// return all start indices of such sub strs
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cassert>
using namespace std;

// time: O(n) * O(1) * O(k), => scan s, find word in map, at most k words
vector<int> findSubstring(string s, vector<string>& words) {
    // use two maps: counts, counted
    unordered_map<string, int> counts;  // as words may contain duplicates
    for (string word : words) counts[word]++;

    vector<int> res;    // indices of result sub str
    int n = s.size();
    int wordLen = words[0].size();
    int wordCnt = words.size();
    for (int i = 0; i < n - wordCnt * wordLen + 1; i++) {
        unordered_map<string, int> counted;
        int j = 0;
        for (; j < wordCnt; j++) {
            // cp a word and find it in map
            string word = s.substr(i + j * wordLen, wordLen);
            if (counts.find(word) != counts.end()) {
                counted[word]++;
                if (counted[word] > counts[word]) break;
            }
            else break;
        }
        if (j == wordCnt) res.push_back(i);
    }
    return res;
}
int main() {
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    vector<int> exp = {0,9};
    vector<int> res = findSubstring(s, words);
    assert(res == exp);
    return 0;
}
