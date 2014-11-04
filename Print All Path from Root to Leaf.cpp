/*
	Facebook Interview Question
	Print all path from root to left -> dfs
 */

#include<vector>
#include<iostream>
using namespace std;

struct node{
	char data;
	node *left;
	node *right;
	node(char d): data(d), left(nullptr), right(nullptr){}
};

class solution_fbpath{
public:
	// dfs
	void printAllPath(node *root){
		if(root == nullptr) return;
		vector<node*> path;
		helper(root, path);
	}

	void helper(node *root, vector<node*> &path){

		// print at leaf node
		if(root->left == nullptr && root->right == nullptr){
			for(node *n : path)
				cout << n->data << " ";
			cout << root->data << " ";
			cout << endl;
			return;
		}

		path.push_back(root);
		helper(root->left, path);
		helper(root->right, path);
		path.pop_back();
	}
};

int main(){
	solution_fbpath *obj = new solution_fbpath();
	node *a = new node('a');
	node *b = new node('b');
	node *c = new node('c');
	node *d = new node('d');
	node *e = new node('e');
	node *f = new node('f');
	node *g = new node('g');
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;
	obj->printAllPath(a);
	return 0;
}