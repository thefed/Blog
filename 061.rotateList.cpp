// LC 61, rotate list 
// Given a list, rotate the list to the right by k places, where k is non-negative.
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next) return head;
    int len = 1;    // list length
    ListNode *tail = head;
    while (tail->next) {
        len++;
        tail = tail->next;
    }
    k %= len;
    if (k == 0) return head;

    ListNode preHead(0);
    preHead.next = head;

    // 1 2 3 4 5, k=2, 
    ListNode *slow = &preHead;
    for (int i = 0; i < len - k; i++) slow = slow->next;
    tail->next = preHead.next;
    preHead.next = slow->next;
    slow->next = NULL;
    return preHead.next;
}
ListNode* createList(vector<int>& items) {
    ListNode preHead(0);
    ListNode *tail = &preHead;
    for (int item : items) {
        tail->next = new ListNode(item);
        tail = tail->next;
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
    vector<vector<int>> itemsList = {
        {},
        {1},
        {1,2},
        {1,2},
        {1,2},
        {1,2,3,4,5}
    };
    vector<vector<int>> exps = {
        {},
        {1},
        {1,2},
        {2,1},
        {1,2},
        {4,5,1,2,3}
    };
    vector<int> nums = {1,1, 0,1,4, 2};
    for (int i = 0; i < itemsList.size(); i++) {
        ListNode *head = createList(itemsList[i]);
        ListNode *res = rotateRight(head, nums[i]);
        printf("test %d\n", i + 1);
        vector<int> resItems = getItems(res);
        assert(resItems == exps[i]);
    }
    return 0;
}