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
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class solution_fbkme{
public:
	int findKthSmallest(vector<vector<int>> &matrix, int k){
		int m = matrix.size();
		if(m == 0) return 0;
		int n = matrix[0].size();
		if(m * n < k) k = k % (m*n);

		priority_queue<int, vector<int>> pq; // max heap default
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(pq.size() < k) pq.push(matrix[i][j]);
				else{
					if(matrix[i][j] < pq.top()){
						pq.pop();
						pq.push(matrix[i][j]);
					}
				}
			}
		}

		cout << pq.top() << endl;
	}
};

int main(){
	solution_fbkme *obj = new solution_fbkme();
	int a1[] = {10, 20, 30, 40};
	int a2[] = {15, 25, 35, 45};
	int a3[] = {24, 29, 37, 48};
	int a4[] = {32, 33, 39, 50};
	vector<int> v1 (a1, a1+4);
	vector<int> v2 (a2, a2+4);
	vector<int> v3 (a3, a3+4);
	vector<int> v4 (a4, a4+4);
	vector<vector<int>> vv;
	vv.push_back(v1);
	vv.push_back(v2);
	vv.push_back(v3);
	vv.push_back(v4);
	obj->findKthSmallest(vv, 3);
	obj->findKthSmallest(vv, 20);
	return 0;
}