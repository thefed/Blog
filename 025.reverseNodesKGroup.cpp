// LC 25, reverse the nodes of a linked list k at a time and return its modified list.
// Given a linked list,
// 1 <= k <= list length
// If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
// You may not alter the values in the nodes, only nodes itself may be changed.
// require space O(1)
// For example,
// Given this linked list: 1->2->3->4->5
// For k = 2, you should return: 2->1->4->3->5
// For k = 3, you should return: 3->2->1->4->5
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(vector<int>& items){
    ListNode preHead(0);
    ListNode *tail = &preHead;
    for (int item : items) {
        tail->next = new ListNode(item);
        tail = tail->next;
    }
    return preHead.next;
}

void deleteList(ListNode *head) {
    while (head) {
        ListNode *deleted = head;
        head = head->next;
        delete deleted;
    }
}

ListNode* reverseKGroup(ListNode* head, int k) {
    // no need to reverse
    if (k == 1 || !head) return head;


    int len = 0;    // length of list
    ListNode preHead(0);
    preHead.next = head;

    // get length of list
    ListNode *curr = preHead.next;
    while (curr) {
        len++;
        curr = curr->next;
    }

    //   1 2 3 4 5
    // p c n
    ListNode *prev = &preHead;

    ListNode *next;
    while (len >= k) {  // ignore if remaining length < k
        curr = prev->next;
        next = curr->next;

        // reverse k nodes from curr
        for (int i = 1; i < k; i++) {
            curr->next = next->next;
            // insert "next" after 'prev'
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        len -= k;
        prev = curr;    // mv "prev" to prev of new k-group
    }

    return preHead.next;
}

vector<int> getItems(ListNode *head) {
    vector<int> items;
    while (head) {
        items.push_back(head->val);
        head = head->next;
    }
    return items;
}

int main() {
    vector<vector<int>> itemsList = {{1,2,3,4,5,6,7}, {2,1,4,3,6,5,7}};
    vector<vector<int>> expItems = {{2,1,4,3,6,5,7}, {1,2,3,4,5,6,7}};
    vector<int> ks = {2, 2};
    for (int i = 0; i < itemsList.size(); i++) {
        vector<int> &items = itemsList[i];
        ListNode *head = createList(items);
        int &k = ks[i];
        ListNode *res = reverseKGroup(head, k);
        vector<int> resItems = getItems(res);
        assert(resItems == expItems[i]);
        deleteList(res);
    }
    return 0;
}
