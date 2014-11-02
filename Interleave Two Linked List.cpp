/*
	Facebook interview question
	Interleave two linked-list
	for example
		Given:
			1->2->3->4
			5->6
		return 
			1->5->2->6->3->4
	solve it iterative & recursive
 */

#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
	node(int d){
		data = d;
		next = nullptr;
	}
};

class solution_fbill{
public:
	// recursive
	node *interleaveTwoLinkedList_recursive(node *l1, node *l2){
		if(l1 == nullptr && l2 == nullptr) return nullptr;
		if(l1 == nullptr) return l2;
		if(l2 == nullptr) return l1;
		l2->next = interleaveTwoLinkedList_recursive(l1->next, l2->next);
		l1->next = l2;
		return l1;
	}

	// interative, assume l1 is longer than l2
	node *interleaveTwoLinkedList_iterative(node *l1, node *l2){
		node *l1_ori = l1;

		while(l2 != nullptr){
			node *l1_nt = l1->next;
			node *l2_nt = l2->next;
			l1->next = l2;
			l2->next = l1_nt;
			l1 = l1_nt;
			l2 = l2_nt;
		}
		return l1_ori;
	}

	void printLinkedList(node *head){
		while(head != nullptr){
			cout << head->data << " ";
			head = head->next;
		}
		cout << endl;
	}
};

int main(){
	solution_fbill *obj = new solution_fbill();
	node *a = new node(1);
	node *b = new node(2);
	node *c = new node(3);
	node *d = new node(4);
	node *e = new node(5);
	node *f = new node(6);
	a->next = b;
	b->next = c;
	c->next = d;
	e->next = f;

	/***** can't test them at the same time *****/

	//node *n = obj->interleaveTwoLinkedList_recursive(a, e);
	//obj->printLinkedList(n);
	node *n = obj->interleaveTwoLinkedList_iterative(a, e);
	obj->printLinkedList(n);

	delete(a);
	delete(b);
	delete(c);
	delete(d);
	delete(e);
	delete(f);
	return 0;
}


