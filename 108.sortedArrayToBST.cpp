// convert sorted array to BST
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<assert.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* sortedArrayToBSTHelper(vector<int> &nums, int start, int end) {
    if (start > end) return NULL;
    //if (nums.empty()) return NULL;
    // 1 2 3 4 5 6 
    //      4
    //     / \
    //    2   6 
    //   / \ / \
    //  1  3 5 
    // the middle element in nums should be root
    // inorder traversal, resurion
    int mid = (start + end) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBSTHelper(nums, start, mid - 1);
    root->right = sortedArrayToBSTHelper(nums, mid + 1, end);
    return root;
}
TreeNode* sortedArrayToBST(vector<int> &nums) {
    return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
}
bool sameTree(TreeNode *root1, TreeNode *root2) {
    if (!root1 && !root2) return true;
    else if (!root1 || !root2) return false; // one of them is null
    // BFS traversal to compare
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    q1.push(root1);
    q2.push(root2);
    while (!q1.empty() && !q2.empty()) {
        int sizeQ1 = q1.size();
        int sizeQ2 = q2.size();
        if (sizeQ1 != sizeQ2) return false;
        for (int i = 0; i < sizeQ1; i++) {
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
    return q1.empty() && q2.empty();
}
void deleteTree(TreeNode *root) {
    if (!root) return;
    // DFS traversal
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    // or BFS traversal, use queue
}
int main() {
    vector<int> nums;
    assert(sortedArrayToBST(nums) == NULL);
    TreeNode *root = new TreeNode(1);
    vector<int> nums2(1, 1);
    assert(sameTree(sortedArrayToBST(nums2), root) == true);
    printf("Success.\n");    
}
