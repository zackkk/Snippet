/*
	Facebook Interview Question
	A(B(D, ), C(E,F))
	Q1: ABD, ACE, ACF
	Q2:
	space space A
	space B
	D
	...
 */

#include<iostream>
#include<vector>
using namespace std;

struct node{
	char val;
	node *left;
	node *right;
	node(char v): val(v), left(nullptr), right(nullptr) {}
};

class solution_fbprt{
public:
	void printPath(node *root){
		if(root == nullptr) return;
		vector<node*> path;
		vector<int> width;
		helper(root, path, width, 0);
	}

	void helper(node *root, vector<node*> &path, vector<int> &width, int cur_width){
		if(root->left == nullptr && root->right == nullptr){// if terminate at nullptr, then path will print twice
			path.push_back(root);
			width.push_back(cur_width);

			int min_width = INT_MAX;
			for(int i : width)
				min_width = min (min_width, i);

			for(int i = 0; i < path.size(); i++){
				int diff = abs(width[i] - min_width);
				while(diff > 0) { cout << "#"; diff--; } // bug happened here
				cout << path[i]->val;
				cout << endl;
			}

			
			path.pop_back();
			width.pop_back();
			return;
		}

		path.push_back(root);
		width.push_back(cur_width);
		if(root->left) helper(root->left, path, width, cur_width-1);
		if(root->right) helper(root->right, path, width, cur_width+1);
		path.pop_back();
		width.pop_back();
	}
};

int main(){
	solution_fbprt *obj = new solution_fbprt();
	node *a = new node('a');
	node *b = new node('b');
	node *c = new node('c');
	node *d = new node('d');
	node *e = new node('e');
	node *f = new node('f');
	a->left = b;
	a->right = c;
	b->left = d;
	c->left = e;
	c->right = f;
	obj->printPath(a);
 	return 0;
}