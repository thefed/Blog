// LC 98, validate BST
#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// iterative in-order traversal, use stack
// time: O(n), space: O(n)
bool isBST(TreeNode *root) {
    if (!root) return true;

    // cmp prev and curr item, curr should > prev
    stack<TreeNode*> st;
    TreeNode *prev = NULL;
    while (root || !st.empty()) {
        while (root) {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        if (prev && root->val <= prev->val) return false;
        prev = root;
        root = root->right;
    }
    return true;
}
TreeNode* createBST(vector<int>& items, int start, int end) {
    if (start > end) return NULL;
    if (start == end) return new TreeNode(items[start]);
    int mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(items[mid]);
    root->left = createBST(items, start, mid - 1);
    root->right = createBST(items, mid + 1, end);
    return root;
}
int main() {
    vector<int> items = {1,2,3,4,5,6};
    TreeNode *root = createBST(items, 0, items.size() - 1);
    assert(isBST(root));

    // disorder items
    swap(items[1], items[4]);
    root = createBST(items, 0, items.size() - 1);
    assert(!isBST(root));
    return 0;
}