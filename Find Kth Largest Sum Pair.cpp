/*
	Facebook Interview Question

	Given two sorted arrays of numbers, we want to find the pair with the kth largest possible sum. 
	(A pair is one element from the first array and one element from the second array). For example, with arrays

	[2, 3, 5, 8, 13]
	[4, 8, 12, 16]
	The pairs with largest sums are

	13 + 16 = 29
	13 + 12 = 25
	8 + 16 = 24
	13 + 8 = 21
	8 + 12 = 20

	So the pair with the 4th largest sum is (13, 8). How to find the pair with the kth largest possible sum?
 */

// O(n^2): n^2 pairs
// O(klogk): max heap, pop one element and push two elements


#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;

struct pairs{
	int val;
	int x;
	int y;
	pairs(int v, int xx, int yy): val(v), x(xx), y(yy) {}
};

bool operator < (const pairs a, const pairs b){
	return a.val < b.val;
}

class solution_fbsp{
public:
	int findKthLargestSumPair(vector<int> &A, vector<int> &B, int k){
		priority_queue<pairs, vector<pairs>> heap; // max heap default
		
		int ia = A.size() - 1;
		int ib = B.size() - 1;
		if(ia < 0 || ib < 0 || k <= 0) return -1; // no pairs

		pairs p (A[ia] + B[ib], ia, ib);
		heap.push(p); 
		int prev = A[ia] + B[ib];
		int count = 1;

		while(count < k){
			if(heap.empty()) return -1;
			pairs p = heap.top();
			heap.pop();

			// avoid duplicate sum
			if(p.val != prev){
				count++;
				prev = p.val;
				//cout << p.val << " (" << p.x << "," << p.y << ")" << endl;
			}
			
			// add two possible max sum
			if(p.x-1 >= 0){ 
				pairs p (A[p.x-1]+B[p.y], p.x-1, p.y);
				heap.push(p); 
			}
			if(p.y-1 >= 0){ 
				pairs p (A[p.x]+B[p.y-1], p.x, p.y-1);
				heap.push(p);
			}
		}

		if(heap.empty()) return -1;
		return prev;
	}
};

int main(){
	solution_fbsp *obj = new solution_fbsp();
	int a[] = {2, 3, 5, 8, 13};
	int b[] = {4, 8, 12, 16};
	vector<int> A (a, a+5);
	vector<int> B (b, b+4);
	cout << obj->findKthLargestSumPair(A, B, 1) << endl;
	cout << obj->findKthLargestSumPair(A, B, 2) << endl;
	cout << obj->findKthLargestSumPair(A, B, 3) << endl;
	cout << obj->findKthLargestSumPair(A, B, 4) << endl;
	cout << obj->findKthLargestSumPair(A, B, 5) << endl;
	cout << obj->findKthLargestSumPair(A, B, 6) << endl;
	cout << obj->findKthLargestSumPair(A, B, 7) << endl;
	return 0;
}