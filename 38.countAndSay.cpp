#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
string countAndSay(int n) {
    string res = "1";

    // iterate (n - 1) times
    for (int k = 0; k < n - 1; k++) {
        string s = res;
        res = "";
        if (s.size() == 1) {
            res = to_string(1) + s[0];
        }
        else {
            int i;
            for (i = 0; i < s.size() - 1; i++) {
                int cnt = 1;    // count the number of repetive chars
                while (i < s.size() - 1 && s[i] == s[i + 1]) {
                    i++;
                    cnt++;
                }
                // now either i == s.size() - 1 or s[i] != s[i + 1]
                // from i to end, all the same chars
                res += to_string(cnt) + s[i];    
            }
            // check if last char equals the previous one
            if (s[s.size() - 1] != s[s.size() - 2]) {
                res += to_string(1) + s[s.size() - 1];    
            }
        }
        cout << res << endl;
    }
    return res;
}
void test() {
    string actual = countAndSay(1);
    assert(actual == "1" && "wrong output");
    printf("SUCCESS\n");

    actual = countAndSay(2);
    assert(actual == "11" && "wrong output");    
    printf("SUCCESS\n");

    actual = countAndSay(3);
    assert(actual == "21" && "wrong output");    
    printf("SUCCESS\n");

    actual = countAndSay(4);
    assert(actual == "1211" && "wrong output");    
    printf("SUCCESS\n");

    actual = countAndSay(5);
    assert(actual == "111221" && "wrong output");    
    printf("SUCCESS\n");
}
int main() {
    test();
}