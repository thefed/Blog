// LC 21, merge two sorted linked lists, return a new list
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// maintain two pointers to lists, choose the smaller one and mv forward
// append the remaining list to result
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode preHead(0);
    ListNode *tail = &preHead;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        }
        else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;  // append the remaining nodes
    return preHead.next;
}
// for test use
vector<int> getItems(ListNode *head) {
    vector<int> items;
    while (head) {
        items.push_back(head->val);
        head = head->next;
    }
    return items;
}
ListNode *createList(vector<int>& items) {
    ListNode preHead(0), *tail = &preHead;
    for (int i : items) {
        tail->next = new ListNode(i);
        tail = tail->next;
    }
    return preHead.next;
}
int main() {
    vector<int> nums1 = {1,3,5,7}, nums2 = {2,4,6,8,10};
    vector<int> exp = {1,2,3,4,5,6,7,8,10};
    ListNode *l1 = createList(nums1), *l2 = createList(nums2);
    ListNode *head = mergeTwoLists(l1, l2);
    vector<int> res = getItems(head);
    assert(res == exp);
    return 0;
}
