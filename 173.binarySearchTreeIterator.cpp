// LC 173, impl BST iterator: bool hasNext() and int next()
// next(): return the next smallest number in the BST.
// next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x),left(NULL),right(NULL) {}
};
class BSTIterator {
private:
	stack<TreeNode *> st;
	// push all nodes till left == null
	void pushTillLeft(TreeNode *root) {
		while (root) {
			st.push(root);
			root = root->left;
		}
	}
public:
	BSTIterator(TreeNode *root) {
		pushTillLeft(root);
	}
	bool hasNext() {
		return !st.empty();
	}
	// return the next smallest num
	int next() {
		TreeNode *m_root = st.top();
		st.pop();
		int val = m_root->val;
		m_root = m_root->right;
		pushTillLeft(m_root);
		return val;
	}
};

TreeNode* createBSTWithRange(vector<int>& items, int start, int end) {
	if (start > end) return NULL;
	if (start == end) return new TreeNode(items[start]);
	int mid = start + (end - start) / 2;
	TreeNode* root = new TreeNode(items[mid]);
	root->left = createBSTWithRange(items, start, mid - 1);
	root->right = createBSTWithRange(items, mid + 1, end);
	return root;
}

TreeNode* createBST(vector<int>& items) {
	return createBSTWithRange(items, 0, items.size() - 1);
}

void scanItems(BSTIterator& i) {
	
}
int main() {
	vector<int> nums = {1,2,3,4,5};
	TreeNode *root = createBST(nums);

	vector<int> res;
	BSTIterator i(root);
	while (i.hasNext()) res.push_back(i.next());

	assert(res == nums);
	return 0;
}