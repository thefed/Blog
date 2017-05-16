// LC 208, impl a trie (prefix tree): insert, search, startWith
// words only contain a-z
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class TrieNode {
    public:
        TrieNode *next[26]; // each node has 26 children
        bool isWord;
        TrieNode(bool b=false) {
            memset(next, 0, sizeof(next));  // set all children as NULL
            isWord = b;
        }
};

class Trie {
private: 
    TrieNode *root;
    TrieNode *find(string key) {
        TrieNode *p = root;
        for (int i = 0; i < key.size() && p; i++) {
            p = p->next[key[i] - 'a'];
        }
        return p;
    }
public: 
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *p = root;
        // check which child should be placed
        for (int i = 0; i < word.size(); i++) {
            if (! p->next[word[i] - 'a']) {
                p->next[word[i] - 'a'] = new TrieNode();
            }
            p = p->next[word[i] - 'a'];
        }
        p->isWord = true;
    }

    bool search(string word) {
        TrieNode *p = find(word);
        return p && p->isWord;
    }

    bool startWith(string prefix) {
        return find(prefix) != NULL;
    }
};

int main() {
    Trie obj; // = new Trie();
    vector<string> words = {"baidu", "baid", "badu"};
    for (string w : words) obj.insert(w);
    for (string w : words) assert(obj.search(w));
    return 0;
}
