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
		while (head) {
			ListNode *deleted = head;
            head = head->next;
			delete deleted;
		}
	}
	ListNode *head;
	void insertListNode(int val) {	// insert from head
		ListNode preHead(0);
		preHead.next = head;
		ListNode *node = new ListNode(val);
		node->next = preHead.next;
		head = node;
	}
	ListNode* deleteListNode(int val) {
		if (head) {
			ListNode preHead(0);
			preHead.next = head;
			ListNode *temp = &preHead;
			while (temp->next != NULL) {
				if (temp->next->val == val) {
					ListNode *del = temp->next;
					temp->next = temp->next->next;
					delete del;
					head = preHead.next;
					break;
				}
			}
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
    ListNode preHead(0);
    preHead.next = head;
    ListNode *prev = &preHead;
    ListNode *curr = prev->next, *next = curr->next;
    //   1 2 3 4
    // p c n
    //   2 1 3 4
    // p   c n
    //     p c
    //   2 1 4 3
    //         p c n
    while (curr && curr->next) {
        printf("mv %d\n", next->val);
        curr->next = next->next;    // store a node

        // insert "next" to front
        next->next = prev->next;
        prev->next = next;

        // next = curr->next; 

        // mv prev to curr, set curr to new start node
        // mv next
        prev = curr;
        curr = prev->next;
        next = curr ? curr->next : NULL;
    }
    // terminate list
    if (!curr) prev->next = NULL;
    else if (!curr->next) prev->next->next = NULL;

    /*
    ListNode *node = &preHead;
    preHead.next = head;         // 1
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
    */
    return preHead.next;
}
void testSwapPairs(){
	LinkedList l;
	// l.print();
	// l.head = swapPairs(l.head);
	// l.print();

	int n = 7;	// create linkedlist
	for (int i = n; i >= 1; i--) {
		l.insertListNode(i);
	}
    printf("in: \n");
	l.print();
	l.head = swapPairs(l.head);
    printf("out: \n");
	l.print();
}
int main(){
	testSwapPairs();
    return 0;
}