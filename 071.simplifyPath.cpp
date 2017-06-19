// LC 71, simpify path
// Given an absolute path for a file (Unix-style), simplify it.

// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
// click to show corner cases.

// Corner Cases:
// Did you consider the case where path = "/../"?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
// In this case, you should ignore redundant slashes and return "/home/foo".

#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <stack>
using namespace std;

void buildPath(string& res, vector<string>& dirs) {
    for (string& dir : dirs) {
        res += "/" + dir;
    }
}

string simplifyPath(string path) {
    string res;
    if (path.empty()) return res;
    int next_slash = 0;
    vector<string> dirs;
    for (size_t i = path.find('/'); i < path.size(); ) {
        // if (path[i] == '/') {, update start statement of loop to remove this if branch
        // check repetive slashes
        while (i + 1 < path.size() && path[i + 1] == '/') i++;

        // if (i + 1 == path.size()) {  // ending slash
        //     break;
        //     // return res;
        // }
        // else {

        if (i != path.size() - 1) {
            next_slash = path.find('/', i + 1);
            string dir = next_slash != string::npos ? path.substr(i + 1, next_slash - i - 1) : 
                path.substr(i + 1);
            if (dir == "..") {
                if (!dirs.empty())  dirs.pop_back();
            }
            else if (dir != ".") {
                dirs.push_back(dir);    // save it
            }
            // else if (dir == ".") // ignore

            i = next_slash;
        }
        else {
            i++;    // last char is '/', exit loop
        }
        // }
        // }
    }

    // convert dirs stack into result path
    buildPath(res, dirs);
    return dirs.empty() ? "/" : res;
}

int main() {
    vector<string> paths = {
        "/home/",
        "/a/./b/../../c/",
        "/../",
        "/home//foo"
    };
    vector<string> exps = {
        "/home",
        "/c",
        "/",
        "/home/foo"
    };
    for (int i = 0; i < paths.size(); i++) {
        string res = simplifyPath(paths[i]);
        printf("test %d, res: %s\n", i + 1, res.c_str());
        assert(res == exps[i]);
    }
    return 0;
}   