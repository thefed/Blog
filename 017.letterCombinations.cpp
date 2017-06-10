// LC 17, letter combinations of a phone number
// Given a digit string, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below.
// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <unordered_map>
using namespace std;

// backtrack
void getCombinations(string& digits, vector<string>& res, string tmpRes, int start) {
    if (tmpRes.size() == digits.size()) {
        res.push_back(tmpRes);
        return;
    }

    unordered_map<char, string> digitToChars = {
        {'0',"0"},{'1',"1"},{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
        {'6',"mno"},{'7',"pqrs"}, {'8',"tuv"},{'9',"wxyz"}
    };

    string chars = digitToChars[digits[start]];
    for (char c : chars) {
        getCombinations(digits, res, tmpRes + c, start + 1);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits.empty()) return res;
    string tmpRes;
    getCombinations(digits, res, tmpRes, 0);
    return res;
}

// iterative method
vector<string> letterCombinations_i(string digits) {
    unordered_map<char, string> digitToChars = {
        {'0',"0"},{'1',"1"},{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
        {'6',"mno"},{'7',"pqrs"}, {'8',"tuv"},{'9',"wxyz"}
    };

    vector<string> res;
    if (digits.empty()) return res;
    res.push_back("");  // to ensure first char can be added
    for (int i = 0; i < digits.size(); i++) {
        string chars = digitToChars[digits[i]];
        vector<string> tmpResults;
        for (char c : chars) {
            // add this char to every string in result
            for (int j = 0; j < res.size(); j++) {
                tmpResults.push_back(res[j] + c);
            }
        }
        res = tmpResults;
    }
    return res;
}

void print(vector<string>& strs, string msg="") {
    cout << msg;
    for (string str : strs) cout << str << " ";
    cout << endl;
}
int main() {
    string digits = "23";
    vector<string> res = letterCombinations(digits);
    vector<string> exp = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    print(res, "res: ");
    assert(res == exp);

    res = letterCombinations_i(digits);
    sort(res.begin(), res.end());
    print(res, "res: ");
    assert(res == exp);

    assert(letterCombinations_i("").empty());
    assert(letterCombinations("").empty());
    return 0;
}
