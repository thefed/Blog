// LC 255, Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
// You may assume each number in the sequence is unique.

#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
using namespace std;
// recursive method, time: T(n) = T(n-1) + O(n) => O(n^2), space: O(n)
bool verifyPreorderSubtree(vector<int>& preorder, int start, int end) {
    if (start >= preorder.size()) return true;
    if (end - start <= 1) return true;  

    // find left tree's end index in preorder
    int leftEnd = start;
    for (int i = start + 1; i <= end; i++) {
        if (preorder[i] < preorder[start]) {
            leftEnd = i;
        }
        else break;
    }
   
    // verify all items from [leftEnd+1] are greater than root
    for (int i = leftEnd + 1; i <= end; i++) {
        if (preorder[i] < preorder[start]) return false;
    }

     // trailing items are > root, verify right tree only
    if (leftEnd == start) return verifyPreorderSubtree(preorder, start + 1, end);

    return verifyPreorderSubtree(preorder, start + 1, leftEnd)
        && verifyPreorderSubtree(preorder, leftEnd + 1, end);
}


// recursive method
bool verifyPreorder_r(vector<int>& preorder) {
    if (preorder.size() <= 2) return true;
    return verifyPreorderSubtree(preorder, 0, preorder.size() - 1);
}

// use stack, iterative method, time: O(n), space: O(n)
bool verifyPreorder(vector<int> preorder) {
    int low = INT_MIN;
    stack<int> visited;
    for (int i : preorder) {
        // printf("i=%d, low=%d\n", i, low);
        // curr node should not be less than right subtree's lower bound
        if (i < low) return false;

        // found a node greater than top, then it must be right tree of stack top node
        while (!visited.empty() && i > visited.top()) {
            low = visited.top();    // update lower bound of right subtree
            visited.pop();
        }

        visited.push(i);    // {4,2,1,}, when 3 comes, pop 1,2, push 3=>{4,3}
    }
    return true;
}

int main() {
/*
       4
    2    6
  1  3  5
*/
    vector<int> preorder = {4,2,1,3,6,5};
    assert(verifyPreorder(preorder));

    // swap(preorder[2], preorder[5]);
    // assert(!verifyPreorder(preorder));

    // preorder = {1,2,3};
    // assert(verifyPreorder(preorder));

    // preorder = {2,3,1};
    // assert(!verifyPreorder(preorder));

    // preorder = {5,2,3,4};
    // assert(verifyPreorder(preorder));
    return 0;
}