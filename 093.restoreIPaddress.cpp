// LC 93, given an array (only digits), 
// return all possible valid IP addresses
// Given "25525511135",
// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>
using namespace std;


inline bool isValidIp(string& s) {
    if (s.size() > 1) {
        return s.size() <= 3 && s[0] != '0' && stoi(s) <= 255;
    }
    else return true;
}
// level: 1~4, marks the segment of ip
// 2 5525511135
// 25 525511135
// 255 255 111 35
void restoreIpFrom(string &s, vector<string>& res, string& tmpRes, int level, int start) {
    // cout << "tmpRes: " << tmpRes << ", ";
    // printf("level: %d, start: %d\n", level, start);

    string end = s.substr(start);
    if (end.size() > (5 - level) * 3) return;
    if (level == 4) {
        if (isValidIp(end)) {
            res.push_back(tmpRes + "." + end);
        }
        return;
    }

    string delim = level == 1 ? "" : ".";
    int maxLen = 3; // max length of a part of ip [0~255]
    for (int len = 1; len <= maxLen && start + len < s.size(); len++) {
        string ip = s.substr(start, len);
        if (!isValidIp(ip)) break;

        ip = delim + ip;    // level 1 ip does not add '.' in front
        tmpRes += ip;
        restoreIpFrom(s, res, tmpRes, level + 1, start + len);
        tmpRes = tmpRes.substr(0, tmpRes.size() - ip.size());
    }
}

// method 1: backtracking, split s into four parts, time: beat 90%
vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    if (s.size() < 4 || s.size() > 12) return res;
    string tmpRes;
    int level = 1;
    restoreIpFrom(s, res, tmpRes, level, 0);
    return res;
}

// method 2: 4 for loops
vector<string> restoreIpAddresses_for(string s) {
    vector<string> res;
    if (s.size() < 4 || s.size() > 12) return res;
    // ip: A.B.C.D, 
    // a,b,c,d: length
    int len = s.size();
    for (int a = 1; a <= 3; a++) {
        if (len - a > 3 * 3) continue;
        string A = s.substr(0, a);
        if (!isValidIp(A)) continue;

        for (int b = 1; b <= 3; b++) {
            if (len - a - b > 2 * 3) continue;
            string B = s.substr(a, b);
            if (!isValidIp(B)) continue;
            for (int c = 1; c <= 3; c++) {
                int d = len - a - b - c;
                if (d > 3 || d < 1) continue;
                string C = s.substr(a + b, c);
                if (isValidIp(C)) {
                    string D = s.substr(a + b + c, d);
                    if (isValidIp(D)) {
                        res.push_back(A + "." + B + "." + C + "." + D);
                    }
                }
            }
        }
    }
    return res;
}

void print(vector<string>& v) {
    for (string s: v) cout << s << " ";
    cout << endl;
}

bool isSame(vector<string>& v1, vector<string>& v2) {
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    return v1 == v2;
}
int main() {
    string s = "25525511135";
    vector<string> res, exp;
    res = restoreIpAddresses(s);
    exp = {"255.255.11.135", "255.255.111.35"};
    print(res);
    assert(isSame(res, exp));

    s = "1111";
    res = restoreIpAddresses(s);
    exp = {"1.1.1.1"};
    print(res);
    assert(isSame(res, exp));

    s = "12340101";
    res = restoreIpAddresses(s);
    exp = {"1.23.40.101", "1.234.0.101", "12.3.40.101", "12.34.0.101", "123.4.0.101", "123.40.10.1"};
    print(res);
    assert(isSame(res, exp));

    res = restoreIpAddresses_for(s);
    print(res);
    assert(isSame(res, exp));
    return 0;
}