// LC 2, addTwoNums.cpp
/*
Input two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

Assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
	ListNode preHead(0);
	ListNode *tail = &preHead;
	int carry = 0;		// carried digit
	while (l1 || l2 || carry) {
		int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
		int digit = sum % 10;
		carry = sum / 10;
		tail->next = new ListNode(digit);
		tail = tail->next;
		l1 = l1 ? l1->next : l1;
		l2 = l2 ? l2->next : l2;
	}
	return preHead.next;
}

ListNode* createList(const vector<int>& items) {
	ListNode preHead(0);
	ListNode *tail = &preHead;
	for (int i : items) {
		tail->next = new ListNode(i);
		tail = tail->next;
	}
	return preHead.next;
}

void print(ListNode *head, string msg="") {
	cout << msg;
	while (head) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}

// return items stored in list as a vector
vector<int> getItems(ListNode *head) {
	vector<int> items;
	while (head) {
		items.push_back(head->val);
		head = head->next;
	}
	return items;
}

int main() {
	vector<int> nums1 = {2,4,3}, nums2 = {5,6,4};
	vector<int> exp = {7,0,8};
	ListNode *l1 = createList(nums1);
	ListNode *l2 = createList(nums2);
	ListNode *head = addTwoNumbers(l1, l2);
	vector<int> res = getItems(head);
	print(l1, "l1: ");
	print(l2, "l2: ");
	print(head, "l1 + l2: ");
	assert(res == exp);

	vector<int> nums3 = {8,8};
	exp = {0,3,4};
	ListNode *l3 = createList(nums3);
	
	head = addTwoNumbers(l1, l3);
	res = getItems(head);
	print(l3, "l3: ");
	print(head, "l1 + l3: ");
	assert(res == exp);
}