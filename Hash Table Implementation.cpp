#include<iostream>
#include<vector>
using namespace std;

struct node{
	int data;
	node *next;
	node(int d): data(d), next(nullptr) {}
};

class hashtable{
private:
	int size;
	vector<node*> hs;

public:
	hashtable(int sz){
		this->size = sz;
		for(int i = 0; i < sz; i++) hs.push_back(nullptr); // set table size
	}
	
	void insert(node* n){
		int index = n->data % this->size;
		if(!hs[index]){ 
			hs[index] = n;
		}
		// append to the end
		else{
			node *cur = hs[index];
			while(cur->next)
				cur = cur->next;
			cur->next = n;
		}
	}

	void find(int key){
		node *cur = hs[key];
		while(cur){
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << endl;
	}
};

int main(){
	hashtable *obj = new hashtable(10);
	obj->insert(new node(5));
	obj->insert(new node(15));
	obj->insert(new node(25));
	obj->find(5);
	return 0;
}