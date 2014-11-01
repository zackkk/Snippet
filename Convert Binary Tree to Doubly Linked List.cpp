/*
	Facebook interview quesion
	http://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
 */

// ask: input? output? <head / root>

#include<iostream>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
	node(int d){
		data = d;
		left = nullptr;
		right = nullptr;
	}
};

class solution_fbcbt {
public:
	node* helper(node* root) {
		if(root == nullptr) return nullptr;

		if(root->left != nullptr){
			node *l = helper(root->left);
			while(l->right != nullptr) l = l->right;
			root->left = l;
			l->right = root;
		}

		if(root->right != nullptr){
			node *r = helper(root->right);
			while(r->left != nullptr) r = r->left;
			root->right = r;
			r->left = root;
		}
		return root;
	}

	node *convertBSTtoBLN(node *root){
		if(root == nullptr) return nullptr;
		node *head = helper(root);
		while(head->left != nullptr) head = head->left;
		return head;
	}
};

int main(){
	solution_fbcbt *obj = new solution_fbcbt();
	node *a = new node(1);
	node *b = new node(2);
	node *c = new node(3);
	node *d = new node(4);
	node *e = new node(5);
	node *f = new node(6);
	node *g = new node(7);
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;
	node *head = obj->convertBSTtoBLN(a);
	while(head != nullptr){
		cout << head->data << " ";
		head = head->right;
	}
	cout << endl;
	return 0;
}