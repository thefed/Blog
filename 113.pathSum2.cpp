// LC 113, Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum
//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1
// sum = 22, return [[5,4,11,2],[5,8,4,5]]

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

// dfs
void findPathSum(TreeNode *root, int sum, vector<vector<int>>& res, vector<int> &tmpRes) {
	if (!root) return;

	tmpRes.push_back(root->val);
	
	// avoid going deeper, reaching leaf and filled sum
	if (sum == root->val && !root->left && !root->right) {
		res.push_back(tmpRes);
		// still need to rm root->val from tmpRes
	}
	if (root->left) findPathSum(root->left, sum - root->val, res, tmpRes);
	if (root->right) findPathSum(root->right, sum - root->val, res, tmpRes);

	tmpRes.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<vector<int>> res;	// paths
	vector<int> tmpRes;
	findPathSum(root, sum, res, tmpRes);
	return res;
}

int main() {
	int sum = 22;
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);

	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);

	vector<vector<int>> exp = {{5,4,11,2},{5,8,4,5}};
	vector<vector<int>> res = pathSum(root, sum);
	assert(res == exp);
	return 0;
}