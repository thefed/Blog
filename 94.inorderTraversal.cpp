// LC 114, binary tree inorder traversal
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
vector<int> inorderTraversal(TreeNode *root) {
	vector<int> res;
	if (!root) return res;

	stack<TreeNode *> st;
	while (root || !st.empty()) {
		if (root) {
			st.push(root);
			root = root->left;
		}
		else {
			root = st.top();
			st.pop();
			// access curr node
			res.push_back(root->val);
			// mv to right child
			root = root->right;	// if right is null, fetch stack top as new root
		}
	}
	return res;
}

// recursive way
vector<int> inorderTraversal_re(TreeNode *root) {
	vector<int> res;
	if (!root) return res;
	vector<int> leftNodes = inorderTraversal_re(root->left);
	vector<int> rightNodes = inorderTraversal_re(root->right);
	res.insert(res.end(), leftNodes.begin(), leftNodes.end());
	res.push_back(root->val);
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
	assert(inorderTraversal(root).empty());

	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	vector<int> exp = {4,2,1,3};	// {1,2,4,3};
	assert(inorderTraversal(root) == exp);
	assert(inorderTraversal_re(root) == exp);
	deleteTree(root);
	return 0;
}
