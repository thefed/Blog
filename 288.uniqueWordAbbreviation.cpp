// LC 288, unique word abbreviation
// An abbreviation of a word follows the form <first letter><number><last letter>
// <number>: the length btw [1] and [n - 2]
// no abbreviation if entire length <= 2
// "it" -> "it"; "dog" => "d1g", "localization" =>  "l10n"
// given dict = {"deer", "door", "cake", "card"}
//unique test:  "dear":0 cart: 1, cane:0, make:1
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <unordered_map>
using namespace std;
class ValidWordAbbr {
private: 
    unordered_map<string, string> map;
    string getKey(string& s) {
        return s.size() <= 2 ? s : s.front() + to_string(s.size() - 2) + s.back();
    }
public:
    ValidWordAbbr(vector<string> dictionary) {
        for (string& word : dictionary) {
            string key = getKey(word);
            if (map.count(key) == 1) {
                // see the same abbr, but a different word, invalidate it to empty
                if (map[key] != word) {
                    // printf("see key: %s again, word: %s\n", key.c_str(), word.c_str());
                    map[key] = "";
                }
            }
            else map[key] = word;
        }
    }
    
    bool isUnique(string word) {
        return map.count(getKey(word)) == 0 || map[getKey(word)] == word;
    }
};

int main() {
    vector<string> dict = {"deer", "door", "cake", "card"};
    vector<string> words = {"dear", "cart", "cane", "make", "hello","card"};
    vector<char> exps = {0,1,0,1,1,1};
    ValidWordAbbr obj(dict);
    for (int i = 0; i < words.size(); i++) {
        bool res = obj.isUnique(words[i]);
        printf("test %d, %-5s: %d\n", i + 1, words[i].c_str(), int(res));
        assert(res == exps[i]);
    }
    string s = "hello";
    cout << s.front();
    cout << s.back();
    return 0;
}