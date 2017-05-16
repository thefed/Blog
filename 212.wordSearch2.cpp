// LC 212, word search 2, Given 
// words = ["oath","pea","eat","rain"] and board =
// [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]
// Return ["eat","oath"].

// how to terminate backtracking earlier?
// use trie! convert all words into a trie
// scan the board, find node recursively
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
class TrieNode {
public:
    TrieNode *next[26];
    // bool isWord;
    string word;
    TrieNode() {
        memset(next, 0, sizeof(next));
        // isWord = b;
    }
};

class Solution {
    // build trie from list of words
    TrieNode *buildTrie(vector<string>& words) {
        TrieNode *root = new TrieNode();
        for (string w : words) {
            TrieNode *p = root;
            for (char c : w) {
                if (!p->next[c - 'a']) {
                    p->next[c - 'a'] = new TrieNode();
                }
                p = p->next[c - 'a'];
            }
            // p->isWord = true;
            // store word directly 
            p->word = w;
        }
        return root;
    }
    
    // find word from root
    void find(vector<vector<char>>& b, int i, int j, TrieNode *p, vector<string>& res) {
        char c = b[i][j];
        if (c == '#' || p->next[c - 'a'] == NULL) return;   // visited or no valid trie node
        p = p->next[c - 'a'];   // mv down 1 level
        if (!p->word.empty()) {
            res.push_back(p->word);    // found one word
            p->word.clear();    // in case met it again
        }   
        
        // mark current position as visited
        b[i][j] = '#';
        
        // search for its neighbors
        if (i > 0) find(b, i - 1, j, p, res);
        if (j > 0) find(b, i, j - 1, p, res);
        if (i < b.size() - 1) find(b, i + 1, j, p, res);
        if (j < b[i].size() - 1) find(b, i, j + 1, p, res);
        b[i][j] = c;            // reset
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        TrieNode *root = buildTrie(words);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                find(board, i, j, root, res);
            }
        }
        return res;
    }
};

int main() {
	vector<string> words = {"oath","pea","eat","rain"};
	vector<vector<char>> board = {
		 {'o','a','a','n'},
		 {'e','t','a','e'},
		 {'i','h','k','r'},
		 {'i','f','l','v'}
	};
	Solution sol;
	vector<string> res = sol.findWords(board, words);
	vector<string> exp = {"eat","oath"};
	sort(res.begin(), res.end());
	sort(exp.begin(), exp.end());
	assert(res == exp);
	return 0;
}