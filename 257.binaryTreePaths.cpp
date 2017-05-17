// LC 257, return the binary tree traversing paths as vector<string>
//   1
// /   \
// 2    3
//  \
//   5
// => ["1->2->5", "1->3"]
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void traverse(TreeNode *root, vector<string>& res, string tmpRes) {
    if (!root) return;
    // if root is alreay leaf, add str without "->"
    string r = to_string(root->val);
    if (!root->left && !root->right) res.push_back(tmpRes + r);
    if (root->left) traverse(root->left, res, tmpRes + r + "->");
    if (root->right) traverse(root->right, res, tmpRes + r + "->");
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res; // paths
    string tmpRes;      // temporary path
    traverse(root, res, tmpRes);
    return res;
}

int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(5);
	vector<string> res = binaryTreePaths(root);
	vector<string> exp = {"1->2->5", "1->3"};
	assert(res == exp);
	return 0;
}