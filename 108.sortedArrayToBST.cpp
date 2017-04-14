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
// recursive solution
TreeNode* sortedArrayToBSTHelper(vector<int> &nums, int start, int end) {
    if (start > end) return NULL;
    else if (start == end) return new TreeNode(nums[start]);
    //if (nums.empty()) return NULL;
    // 1 2 3 4 5 6 
    //      4
    //     / \
    //    2   6 
    //   / \ / \
    //  1  3 5 
    // the middle element in nums should be root
    // inorder traversal, resurion
    int mid = (start + end + 1) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBSTHelper(nums, start, mid - 1);
    root->right = sortedArrayToBSTHelper(nums, mid + 1, end);
    return root;
}
TreeNode* sortedArrayToBST(vector<int> &nums) {
    return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
}
// LC 100: same tree, iterative solution
// recursive solution: 2 lines
// if (!p || !q) return p == q; // one of the given roots is NULL
// return sameTree(p->val == q->val && sameTree(p->left, q->left) && sameTree(p->right, q->right));
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
        assert(sizeQ1 == sizeQ2);
        if (sizeQ1 != sizeQ2) return false;
        for (int i = 0; i < sizeQ1; i++) {
            TreeNode *curr1 = q1.front();
            q1.pop();
            TreeNode *curr2 = q2.front();
            q2.pop();
            assert(curr1->val == curr2->val);
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
void inorderPrint(TreeNode *root) {
    queue<TreeNode*> q;
    printf("Tree inorder: ");
    if (!root) return;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *curr = q.front();
            q.pop();
            printf("%d ", curr->val);
            if (curr->left) q.push(curr->left); 
            if (curr->right) q.push(curr->right); 
        }
    }
    printf("\n");
}
int main() {
    vector<int> nums;
    assert(sortedArrayToBST(nums) == NULL);
    // test single root, with value 4
    TreeNode *root = new TreeNode(4);
    vector<int> nums2(1, 4);
    assert(sameTree(sortedArrayToBST(nums2), root) == true);

    // create an example tree
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    int array[6] = {1, 2, 3, 4, 5, 6};
    vector<int> nums3(array, array + sizeof(array) / sizeof(int));
    inorderPrint(root);
    inorderPrint(sortedArrayToBST(nums3));
    assert(sameTree(sortedArrayToBST(nums3), root) == true);

    deleteTree(root);
    printf("Success.\n");    
}
