/*
	一个天平，有一端是一个N pounds的人。另一端可放置3,7,16三种砝码，求最少砝码数的方法，如没有，print 0。
	这题第一反应greedy，但是自己举了一个反例发现不对。如X=24，结果应该返回[7,7,7,3]。
*/

// all combinations

#include<vector>
#include<iostream>
using namespace std;
class solution_scale {
private:
	vector<int> ret;
public:
	void findCombinations(vector<int> &weights, int N){
		vector<int> cur;
		dfs(weights, N, cur, 0, 0, INT_MAX);
		cout << ret.size() << endl;
		return;
	}

	void dfs(vector<int> &weights, int N, vector<int> &cur, int sum, int index, int minLen){
		// find all possible combinations
		if(sum == N){
			// ret contains numbers of the min size
			if(cur.size() < minLen){ // bug here
				minLen = cur.size();
				ret = cur;
			}
			return;
		}

		for(int i = index; i < weights.size(); i++){
			if(sum + weights[i] <= N){
				cur.push_back(weights[i]);
				dfs(weights, N, cur, sum+weights[i], i, minLen);
				cur.pop_back();
			}
		}
	}
};

int main(){
	solution_scale *obj = new solution_scale();
	vector<int> weights;
	weights.push_back(3);
	weights.push_back(7);
	weights.push_back(16);
	obj->findCombinations(weights, 24);
	return 0;
}