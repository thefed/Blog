#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
string decodeStrFrom(const string &s, int &i) {
    string res;
    // int i = index;
    for (; i < s.size() && s[i] != ']'; i++) {
        if (isdigit(s[i])) {
            int times = 0;
            while (i < s.size() && isdigit(s[i])) {
                times = times * 10 + s[i] - '0';
                i++;
            }
            i++;    // skip '['
            string tmp = decodeStrFrom(s, i);
            // i++;    // skip ']', since next iteration i will increment by itself
            
            // append string if times > 1
            for (int j = 0; j < times; j++) {
                res += tmp;
            }
        }
        else {
            res += s[i];
        }
    }
    return res;
}
string decodeString(string s) {
    int index = 0;  // pass by reference
    return decodeStrFrom(s, index);
}
void test() {
	string s = "3[a]2[bc]";
	string actual = decodeString(s);
	assert(actual == "aaabcbc" && "wrong output");
}
int main() {
	test();
}