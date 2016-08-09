#include<iostream>
#include<assert.h>
using namespace std;
struct ListNode{
	int val; 
	ListNode *next;
	ListNode(int val, ListNode *next=NULL): val(val), next(next){}
};
class LinkedList {
public:
	LinkedList(): head(NULL){}
	~LinkedList() {
		while (head != NULL) {
			ListNode *temp = head;
			delete temp;
			head = head->next;
		}
	}
	ListNode *head;
	void insertListNode(int val) {	// insert from head
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *node = new ListNode(val);
		node->next = dummy->next;
		head = node;
		delete dummy;
	}
	ListNode* deleteListNode(int val) {
		if (head != NULL) {
			ListNode *dummy = new ListNode(0);
			dummy->next = head;
			ListNode *temp = dummy;
			while (temp->next != NULL) {
				if (temp->next->val == val) {
					ListNode *del = temp->next;
					temp->next = temp->next->next;
					delete del;
					head = dummy->next;
					break;
				}
			}
			delete dummy;
			return head;
		}
		return NULL;
	}
	void print() {
		if (head == NULL) {
			cout << "Empty LinkedList\n";
		}
		else {
			ListNode *temp = head;
			while (temp->next != NULL) {
				cout << temp->val << "->";
				temp = temp->next;
			}
			cout << temp->val << endl;
		}
	}
};

ListNode* swapPairs(ListNode* head) {
    if (!head || !(head->next))
        return head;
    ListNode *dummy = new ListNode(0);
    ListNode *node = dummy;
    dummy->next = head;         // 1
    while (head && head->next){ // 1 2 3 4 5 6
        // swap nodes
        ListNode *temp = head->next;    // temp = 2
        head->next = temp->next;        // 1->3
        temp->next = head;              // 2->1
        // move head forward
        node->next = temp;              // new head = 2, save it to node; // ->2
        node = head;                    // n = 1; 4
        head = node->next;
    }
    ListNode *newHead = dummy->next;
    delete dummy;
    return newHead;
}
void testSwapPairs(){
	LinkedList l;
	// l.print();
	// l.head = swapPairs(l.head);
	// l.print();

	int n = 6;	// create linkedlist
	for (int i = n; i >= 1; i--) {
		l.insertListNode(i);
	}
	l.print();
	l.head = swapPairs(l.head);
	l.print();
}
int main(){
	testSwapPairs();
}