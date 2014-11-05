/*
	Given an n x n matrix, where every row and column is sorted in non-decreasing order. 
	Find the kth smallest element in the given 2D array.

	For example, consider the following 2D array.

        10, 20, 30, 40
        15, 25, 35, 45
        24, 29, 37, 48
        32, 33, 39, 50
	The 3rd smallest element is 20 and 7th smallest element is 30
 */

// LeetCode: merge K linked list

// maintain a min heap which keeps elements in the first column at the beginning
// then we can get the min, and then push the next of min into the heap
// time complexity: O(klogn)

#include<iostream>
#include<queue>
using namespace std;

// need to use heap node to get its next element at the same row, int pointer doesn't work 
struct node{
	int val;
	int row;
	int col;
	node(int v, int r, int c): val(v), row(r), col(c){}
};

struct cmp{
	bool operator () (const node *a, const node *b){
		return b->val < a->val;
	}
};

class solution_fbks{
public:
	int findKthSmallest(int matrix[4][4], int n, int k){
		priority_queue<node*, vector<node*>, cmp> minheap;

		// first column of the matrix
		for(int i = 0; i < n; i++)
			minheap.push(new node(matrix[i][0], i, 0));

		// pop off the first k-1 smallest elements
		for(int i = 1; i < k; i++){
			if(minheap.empty()) return -1; // less than k elements

			node *tmp = minheap.top();
			minheap.pop();
			if(tmp->col + 1 < n){
				int r = tmp->row;
				int c = tmp->col+1;
				minheap.push(new node(matrix[r][c], r, c));
			}
		}
		return minheap.top()->val;
	}
};

int main(){
	solution_fbks *obj = new solution_fbks();
	int matrix[4][4] = {{10, 20, 30, 40},
						{15, 25, 35, 45},
						{25, 29, 37, 48},
						{32, 33, 39, 50},
						};
	cout << obj->findKthSmallest(matrix, 4, 3) << endl;
	cout << obj->findKthSmallest(matrix, 4, 7) << endl;
	return 0;
}