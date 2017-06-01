// LC 23, merge k sorted lists
// return it as one sorted list. Analyze and describe its complexity.

// divide and conquer
// T(k) = 2T(k/2) + O(n*k) = 2^2T(k/4) + 2O(nk)
// O(n*k logk)
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// recursive way to merge two lits
ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

// iterative merge
ListNode* mergeTwoLists_i(ListNode *l1, ListNode *l2) {
    ListNode preHead(0);
    ListNode* tail = &preHead;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        }
        else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return preHead.next;
}

// time: O(nk * logk), k lists, avg list length: n
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return NULL;

    int len = lists.size();
    while (len > 1) {
        for (int i = 0; i < len / 2; i++) {
            lists[i] = mergeTwoLists_i(lists[i], lists[len - 1 - i]);
        }
        len = (len + 1) / 2;    // 3 or 4 lists both merged to 2 lists
    }
    return lists.front();
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
        ListNode *deleted = head;
        head = head->next;
        delete deleted;
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
    vector<vector<int>> itemLists = {{1,3,5}, {2,4,6}, {3,4,7}};
    vector<int> expItems = {1,2,3,3,4,4,5,6,7};
    vector<ListNode*> lists;
    for (vector<int>& items : itemLists) {
        lists.push_back(createList(items));
    }
    ListNode *res = mergeKLists(lists);
    vector<int> resItems = getItems(res);
    assert(resItems == expItems);
    deleteList(res);
    return 0;
}