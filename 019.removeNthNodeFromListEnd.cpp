// LC 19, rm n-th node from end of list, 1 <= n <= length
// requirement: 1 pass
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// two pointers: fast/slow, mv "fast" n steps first
// mv both another (length - n) steps
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head) return head;

    ListNode preHead(0);
    preHead.next = head;
    ListNode *fast = &preHead;
    ListNode *slow = &preHead;
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    ListNode *deleted = slow->next;
    slow->next = slow->next->next;
    delete deleted;
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
void deleteList(ListNode *head) {
    while (head) {
        ListNode *node = head;
        head = head->next;
        delete node;
    }
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
        {1,2,3,4,5}
    };
    vector<int> ns = {1, 1, 2};
    vector<vector<int>> expItems = {
        {},
        {},
        {1,2,3,5}
    };
    for (int i = 0; i < itemsList.size(); i++) {
        vector<int>& items = itemsList[i];
        ListNode *head = createList(items);
        int &n = ns[i];
        ListNode *res = removeNthFromEnd(head, n);
        vector<int> resItems = getItems(res);
        assert(resItems == expItems[i]);
        deleteList(res);
    }
    return 0;
}
