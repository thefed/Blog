// LC 148, Sort a linked list in O(n log n) time using constant space complexity.
#include <iostream>
#include <cassert>
#include <algorithm>	// is_sorted
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// sort a list, merge sort
ListNode *sortList(ListNode *head) {
	if (!head || !head->next) return head;

	// split list into two halfs
	ListNode *slow = head, *fast = head;
	while (fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	// {1,2,3,4,5,6,7}, f=7, s=4
	ListNode *head2 = slow->next;
	slow->next = NULL;

	// sort two lists respectively
	ListNode *l1 = sortList(head);
	ListNode *l2 = sortList(head2);

	// merge two sorted lists
	return mergeTwoLists(l1, l2);
}
// merge two sorted lists
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

ListNode *createList(vector<int>& items) {
	ListNode preHead(0);
	ListNode *tail = &preHead;
	for (int i : items) {
		tail->next = new ListNode(i);
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
	vector<int> items = {5,4,1,2,6,3,7};
	ListNode *head = createList(items);
	head = sortList(head);
	vector<int> res = getItems(head);
	sort(items.begin(), items.end());
	assert(res == items);
	deleteList(head);
	return 0;
}