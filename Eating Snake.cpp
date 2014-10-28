/*
	You are given a grid of numbers. A snake sequence is made up of adjacent numbers such that for each number, 
	the number on the right or the number below it is +1 or -1 its value. 
	For example, 

	1 3 2 6 8 
	-9 7 1 -1 2 
	1 5 0 1 9 

	In this grid, (3, 2, 1, 0, 1) is a snake sequence. 

	Given a grid, find the longest snake sequences and their lengths (so there can be multiple snake sequences with the maximum length).
*/
#include<vector>
#include<iostream>
using namespace std;
class solution_es{
public:
	int findLongestSnake(vector<vector<int>> &matrix){
		int m = matrix.size();
		int n = matrix[0].size();
		int ret = 0;
		vector<vector<int>> lengths (m, vector<int> (n, 1));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(i - 1 >= 0 && abs(matrix[i][j] - matrix[i-1][j]) == 1) 
					lengths[i][j] = max(lengths[i][j], lengths[i-1][j]+1);
				if(j - 1 >= 0 && abs(matrix[i][j] - matrix[i][j-1]) == 1) 
					lengths[i][j] = max(lengths[i][j], lengths[i][j-1]+1);
				cout << lengths[i][j] << "  ";
				ret = max(ret, lengths[i][j]);
			}
			cout << endl;
		}
		return ret;
	}
};

int main(){
	solution_es *obj = new solution_es();
	int a1[] = {1,3,2,6,8};
	int a2[] = {-9,7,1,-1,2};
	int a3[] = {1,5,0,1,9};
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	v1.assign(a1,a1+5);
	v2.assign(a2,a2+5);
	v3.assign(a3,a3+5);
	vector<vector<int>> vv;
	vv.push_back(v1);
	vv.push_back(v2);
	vv.push_back(v3);
	cout << obj->findLongestSnake(vv) << endl;
	return 0;
}
