// LC 95, return all structurally unique BST (binary search trees) that store values 1...n.
// Given an integer n, 
// For example,
// Given n = 3, your program should return all 5 unique BST's shown below.
/*
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 1..n is the inorder traversal of BST,
// pick each num i from 1~n as root, generate tree with range [1~i-1], [i+1~n]
vector<TreeNode*> generateTreesByRange(int start, int end) {
    vector<TreeNode*> res;
    if (start > end) {
        res = {NULL};
        return res;
    }
    if (start == end) {
        res = {new TreeNode(start)};
        return res;
    }

    vector<TreeNode*> leftTrees, rightTrees;
    // pick i as root
    for (int i = start; i <= end; i++) {
        leftTrees = generateTreesByRange(start, i - 1);
        rightTrees = generateTreesByRange(i + 1, end);

        for (auto leftTree : leftTrees) {
            for (auto rightTree : rightTrees) {
                TreeNode *root = new TreeNode(i);
                root->left = leftTree;
                root->right = rightTree;
                res.push_back(root);
            }
        }
    }
    return res;
}
vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return vector<TreeNode *> ();
    // as n = 0, start > end, should return empty vector, instead of vector {NULL}
    return generateTreesByRange(1, n);
}
int main() {
    int n = 3;
    vector<TreeNode*> res, exp;
    res = generateTrees(n);
    cout << res.size() << endl;
    assert(res.size() == 5);
    return 0;
}