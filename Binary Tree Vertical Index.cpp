/* Facebook Interview Quesion
		a
	   / \
      b   c
	 / \   \
    d   g   z
	 \     /
	  e   i
	     /
		q
	   /
	  x
	 /
	y

	print: dy
	       bex
		   agq
		   ci
		   z

 */



#include<iostream>
#include<map>
#include<queue>
using namespace std;

struct node{
	char data;
	node *left;
	node *right;
	node(char d){
		data = d;
		left = nullptr;
		right = nullptr;
	}
};

class solution_fbbrvi {
public:
	// bfs + map
	void verticalIndex(node *root){
		map<int, queue<node*>> mymap;
		int min_ver_index = INT_MAX;
		int max_ver_index = INT_MIN;

		queue<node *> cur_node_q;
		queue<int> cur_ver_index_q; // vertical index for the current level nodes
		
		cur_node_q.push(root);
		cur_ver_index_q.push(0);

		while(!cur_node_q.empty()){
			queue<node*> nt_node_q;
			queue<int> nt_ver_index_q;  // vertical index for the next level nodes
			while(!cur_node_q.empty()){
				node *tmp_node = cur_node_q.front();
				int tmp_ver_index = cur_ver_index_q.front();
				cur_node_q.pop();
				cur_ver_index_q.pop();

				// update map, min_ver_index & max_ver_index
				mymap[tmp_ver_index].push(tmp_node);
				min_ver_index = min(min_ver_index, tmp_ver_index);
				max_ver_index = max(max_ver_index, tmp_ver_index);

				if(tmp_node->left){
					nt_node_q.push(tmp_node->left);
					nt_ver_index_q.push(tmp_ver_index-1);
				}
				if(tmp_node->right){
					nt_node_q.push(tmp_node->right);
					nt_ver_index_q.push(tmp_ver_index+1);
				}
			}

			cur_node_q = nt_node_q;
			cur_ver_index_q = nt_ver_index_q;
		}

		printInfo(mymap, min_ver_index, max_ver_index);
	} 

	void printInfo(map<int, queue<node*>> &mymap, int l, int h){
		for(int i = l; i <= h; i++){
			queue<node*> q = mymap[i];
			while(!q.empty()){
				char c = q.front()->data;
				q.pop();
				cout << c << " ";
			}
			cout << endl;
		}
	}
};

int main(){
	solution_fbbrvi *obj = new solution_fbbrvi();
	node *a = new node('a');
	node *b = new node('b');
	node *c = new node('c');
	node *d = new node('d');
	node *e = new node('e');
	node *g = new node('g');
	node *z = new node('z');
	node *i = new node('i');
	node *q = new node('q');
	node *x = new node('x');
	node *y = new node('y');
	
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = g;
	d->right = e;
	c->right = z;
	z->left = i;
	i->left = q;
	q->left = x;
	x->left = y;

	obj->verticalIndex(a);
	return 0;
}