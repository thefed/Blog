// impl BST: search, insert and delete operation
#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* createBST(vector<int>& items, int start, int end) {
    if (start > end) return NULL;
    if (start == end) return new TreeNode(items[start]);
    int mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(items[mid]);
    root->left = createBST(items, start, mid - 1);
    root->right = createBST(items, mid + 1, end);
    return root;
}

// in-order traverse
vector<int> getItems(TreeNode *root) {
    vector<int> items;
    stack<TreeNode*> st;
    while (root || !st.empty()) {
        while (root) {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        items.push_back(root->val);
        root = root->right;
    }
    return items;
}

// search for a node with key=x
TreeNode* search(TreeNode *root, int x) {
    if (!root || root->val == x) return root;
    if (x < root->val) return search(root->left, x);
    else return search(root->right, x);
}

// insert a ndoe with key=x
TreeNode* insert(TreeNode *root, int x) {
    if (!root) return new TreeNode(x);
    if (x < root->val) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    // return the real root
    return root;
}

TreeNode* getSuccessor(TreeNode *root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}
// delete a node with key=x
// 3 cases: deleted node is leaf: rm it
// deleted node has only 1 child: copy it to node, then rm it
// deleted node has two children: copy its inorder successor to node, then rm it
TreeNode *deleteNode(TreeNode *root, int x) {
    if (!root) return root;

    if (x < root->val) root->left = deleteNode(root->left, x);
    else if (x > root->val) root->right = deleteNode(root->right, x);
    else {  // ==
        if (!root->left) {  // has only right child/or leaf node
            TreeNode *rightChild = root->right;
            delete root;
            return rightChild;
        }
        else if (!root->right) {    // has only left child
            TreeNode *leftChild = root->left;
            delete root;
            return leftChild;
        }
        else {  // two children
            TreeNode *successor = getSuccessor(root->right);
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }
    }
    return root;
}
void print(vector<int>& v) {
    for (int i : v) printf("%d ", i);
    printf("\n");
}
int main() {
    vector<int> items = {2,10,16,20, 30, 40, 50};   // root=20
    TreeNode *root = createBST(items, 0, items.size() - 1);

    for (int i = 0; i < items.size(); i++) {
        TreeNode *res = search(root, items[i]);
        assert(res);
        assert(res->val == items[i]);
    }

    root = insert(root, 1);
    vector<int> resItems = getItems(root);
    vector<int> expItems = {1, 2,10,16,20, 30, 40, 50};
    assert(resItems == expItems);

    root = deleteNode(root, 20);
    expItems = {1,2,10,16,30,40,50};
    resItems = getItems(root);
    print(resItems);
    assert(resItems == expItems);

    for (int i = 0; i < expItems.size(); i++) {
        root = deleteNode(root, expItems.back());
        expItems.pop_back();
        resItems = getItems(root);
        assert(resItems == expItems);
    }

    return 0;
}