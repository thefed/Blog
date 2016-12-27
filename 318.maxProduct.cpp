// max product of word lengths (two words do not share common chars), only lowercase chars
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<assert.h>
using namespace std;
int maxProduct(vector<string> &words) {
    vector<int> marks(words.size(), 0);
    // each mark stores the a-z flags of a word
    for (int i = 0; i < words.size(); i++) {
        // for each word
        for (int j = 0; j < words[i].size(); j++) {
            marks[i] |= (1 << (words[i][j] - 'a'));
        }
    }
    int maxProduct = 0;
    for (int i = 0; i < words.size(); i++) {
        for (int j = i + 1; j < words.size(); j++) {
            if ((marks[i] & marks[j]) == 0) {
                int newProd = words[i].size() * words[j].size();
                maxProduct = max(maxProduct, newProd);
            }
        }
    }
    return maxProduct;
}
int main() {
    vector<string> words = {"abcd", "boo", "feg", "abcdef"};
    int res = maxProduct(words);
    assert(res == 12);
    return 0;
}
