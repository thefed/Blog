#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;
struct TreeNode{
    int val; TreeNode *left, *right;
    TreeNode(int v): val(v), left(NULL), right(NULL) {}
};

// LC 100: is same tree
// recursive solution: 2 lines
bool isSameTree1(TreeNode *p, TreeNode *q) {
    if (!p || !q) return p == q;    // if one of the given roots is NULL, check the other
    return p->val == q->val && isSameTree1(p->left, q->left) && isSameTree1(p->right, q->right);
}

// iterative solution, level order
bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p || !q) return p == q;
    queue<TreeNode *> q1, q2;
    q1.push(p);
    q2.push(q);
    while (!q1.empty() && !q2.empty()) {
        int size1 = q1.size(), size2 = q2.size();
        if (size1 != size2) return false;
        for (int i = 0; i < size1; i++) {
            // two current nodes should share the same value
            TreeNode *curr1 = q1.front();
            q1.pop();
            TreeNode *curr2 = q2.front();
            q2.pop();
            if (curr1->val != curr2->val) return false;
            // check left subtree
            if (!curr1->left && !curr2->left) {}
            else if (!curr1->left || !curr2->left) return false;
            else {
                q1.push(curr1->left);
                q2.push(curr2->left);
            }
            // check right subtree
            if (!curr1->right && !curr2->right) {}
            else if (!curr1->right || !curr2->right) return false;
            else {
                q1.push(curr1->right);
                q2.push(curr2->right);
            }
        }
    }
    return true;
}

TreeNode *createTreeHelper(const vector<int> &nums, int start, int end) {
    if (start > end) return NULL;
    if (start == end) return new TreeNode(nums[start]);
    int mid = (start + end + 1) / 2;    // when n=6, mid=3, the 4th item
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = createTreeHelper(nums, start, mid - 1);
    root->right = createTreeHelper(nums, end, mid + 1);
    return root;
}
// create BST from sorted array
TreeNode* createTree(const vector<int> &v) {
    return createTreeHelper(v, 0, v.size() - 1);
}

// free memory
void deleteTree(TreeNode *root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
int main() {
    TreeNode *p = NULL, *q = NULL;
    assert(isSameTree(p, q)); 

    p = new TreeNode(4);
    assert(!isSameTree(p, q));
    deleteTree(p);

    vector<int> nums;
    int n = 6;
    for (int i = 1; i <= n; i++) nums.push_back(i);
    p = createTree(nums);
    q = createTree(nums);
    assert(isSameTree(p, q));

    deleteTree(p);
    deleteTree(q);
    return 0;
}
