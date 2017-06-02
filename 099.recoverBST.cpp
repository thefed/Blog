// LC 99, recover BST, given a BST with a pair of nodes swaped
// recover it, do not change its structure
#include <iostream>
#include <cassert> 
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 1 2 3 4 5 6
// 1 5 3 4 2 6
// find 1st and last decresing pair
void recoverTree(TreeNode *root) {
    if (!root) return;

    TreeNode *first(NULL), *second(NULL);
    // first and second node to be swapped back
    stack<TreeNode*> st;
    TreeNode *prev(NULL);
    while (root || !st.empty()) {
        while (root) {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        // when first is not NULL, prev must have been set
        if (!first && prev && prev->val >= root->val) {
            first = prev;
        }

        if (first && prev->val >= root->val) {
            second = root;
        }
        prev = root;
        root = root->right;
    }

    swap(first->val, second->val);
}

bool isBST(TreeNode *root) {
    if (!root) return true;
    TreeNode *prev = NULL;
    stack<TreeNode*> st;
    while (root || !st.empty()) {
        while (root) {
            st.push(root);
            root = root->left;
        }

        root = st.top();
        st.pop();
        if (prev && prev->val >= root->val) {
            return false;
        }
        prev = root;
        root = root->right;
    }
    return true;
}

TreeNode* createBST(vector<int>& nums, int start, int end) {
    if (start > end) return NULL;
    if (start == end) return new TreeNode(nums[start]);
    int mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(nums[mid]);

    root->left = createBST(nums, start, mid - 1);
    root->right = createBST(nums, mid + 1, end);
    return root;
}

int main() {
    vector<int> nums = {1,5,3,4,2,6};   // {2,5} swapped
    TreeNode *root = createBST(nums, 0, nums.size() - 1);
    assert(!isBST(root));

    recoverTree(root);
    assert(isBST(root));
    return 0;
}