// LC 114, binary tree preorder traversal
#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> preorderTraversal(TreeNode *root) {
	vector<int> res;
	if (!root) return res;

	stack<TreeNode *> st;
	st.push(root);
	while (!st.empty()) {
		root = st.top();
		st.pop();
		// access curr node
		res.push_back(root->val);
		// then check right child (first in, last out)
		if (root->right) st.push(root->right);
		if (root->left) st.push(root->left);
	}
	return res;
}

// recursive way
vector<int> preorderTraversal_re(TreeNode *root) {
	vector<int> res;
	if (!root) return res;
	vector<int> leftNodes = preorderTraversal_re(root->left);
	vector<int> rightNodes = preorderTraversal_re(root->right);
	res.push_back(root->val);
	res.insert(res.end(), leftNodes.begin(), leftNodes.end());
	res.insert(res.end(), rightNodes.begin(), rightNodes.end());
	return res;
}
void deleteTree(TreeNode *root) {
	if (!root) return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete(root);
}
int main() {
	//  	1
	//	  2   3 
	//   4
	TreeNode *root = NULL;
	assert(preorderTraversal(root).empty());

	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	vector<int> exp = {1,2,4,3};
	assert(preorderTraversal(root) == exp);
	assert(preorderTraversal_re(root) == exp);
	deleteTree(root);
	return 0;
}