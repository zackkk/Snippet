
#include<vector>
#include<iostream>
using namespace std;
class solution_won {
public:
	// find all n digits well ordered number, e.g. 149 not 194
	void wellOrderedNumber(int n){
		vector<int> v;
		dfs(n, 1, v);
	}

	void dfs(int n, int cur, vector<int> &v){
		if(v.size() == n){
			for(int ii : v)
				cout << ii;
			cout << endl;
			return; // bug here 
		}

		for(int i = cur; i <= 9; i++){
			v.push_back(i);
			dfs(n, i+1, v); // bug here 
			v.pop_back();
		}
	}
};

int main(){
	solution_won *obj = new solution_won();
	obj->wellOrderedNumber(3);
}