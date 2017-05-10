// LC 147, Sort a linked list using insertion sort
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>	// is_sorted
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
void print(ListNode *head) {
	while (head) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}
// sort a list, merge sort
ListNode *insertionSortList(ListNode *head) {
	if (!head || !head->next) return head;

	print(head);	// {5,3,1}
	ListNode preHead(0);
	ListNode *pre = &preHead, *curr = head;
	while (curr) {
		ListNode *next = curr->next;

		// find the insertion place, 'pre->next' starts at 'head'
		while (pre->next && pre->next->val < curr->val) {
			pre = pre->next;
		}

		// insert "curr" to "pre" and "pre->next"
		curr->next = pre->next;	// add {3} in front of {5}
		pre->next = curr;	// {5}
		pre = &preHead;		// reset "pre" to preHead
		curr = next;

		print(preHead.next);
	}
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
	head = insertionSortList(head);
	vector<int> res = getItems(head);
	sort(items.begin(), items.end());
	assert(res == items);
	deleteList(head);
	return 0;
}
/*
5 4 1 2 6 3 7 
5 
4 5 
1 4 5 
1 2 4 5 
1 2 4 5 6 
1 2 3 4 5 6 
1 2 3 4 5 6 7 
*/