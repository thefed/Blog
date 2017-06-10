// LC 110, check if a tree is height-balanced
// which the depth of the two subtrees of every node never differ by more than 1.
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// return the height of tree, if tree is not balanced, return 1
int getHeight(TreeNode *root) {
    if (!root) return 0;
    int leftHeight = getHeight(root->left);
    if (leftHeight == -1) return -1;
    int rightHeight = getHeight(root->right);
    if (rightHeight == -1 || abs(leftHeight - rightHeight) > 1) return -1;
    return 1 + max(leftHeight, rightHeight);
}

// method: DFS, check height of left/right tree
// time: O(n), space: O(logn) if balanced, worst: O(n)
bool isBalanced(TreeNode *root) {
    return getHeight(root) != -1;
}

TreeNode *createTree(vector<int>& items, int start, int end) {
    if (start > end) return NULL;
    if (start == end) return new TreeNode(items[start]);
    int mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(items[mid]);
    root->left = createTree(items, start, mid - 1);
    root->right = createTree(items, mid + 1, end);
    return root;
}
void deleteTree(TreeNode *root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}
int main() {
    vector<vector<int>> itemsList = {
        {}, {1}, {1,2}, {1,2,3}};

    bool res;
    for (int i = 0; i < itemsList.size(); i++) {
        TreeNode *root = createTree(itemsList[i], 0, itemsList[i].size() - 1);
        res = isBalanced(root);
        printf("test %d: res: %d\n", i + 1, int(res));
        deleteTree(root);
        assert(res);
    }

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    assert(!isBalanced(root));
    deleteTree(root);
    return 0;
}
