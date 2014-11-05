/*
	Facebook Interview Question
	jump river的题目, 给一个数组[1,0,1,0,1], 1代表可以站, 0不可以站. 
	从速度为1开始往前跳, 每次跳的时候, 可以跳当前速度那么多格, 也可以跳当前速度+1那么多格. 
	问最少跳几次可以跳过河(即跳出数组), 或者跳不过河. 解法直接递归+cache就可以. 
	上面的例子跳2次就能跳过河了, 第一次从index=0, 速度为1跳到2, 然后速度为2刚好跳出去.
 */

// Leetcode Jump Game 2 ? -> speed is changing.

#include<iostream>
#include<vector>
using namespace std;

class solution_fbjr{
private:
	int min_steps;
public:
	solution_fbjr(): min_steps(INT_MAX) {}

	int jumpRiver(vector<int> &arr){
		if(arr.size() == 0 || arr[0] == 0) return -1;
		helper(arr, 1, 0, 0);
		return min_steps;
	}

	void helper(vector<int> &arr, int v, int pos, int steps){
		if(pos >= arr.size()){
			min_steps = min(steps, min_steps);
			return;
		}

		bool can_jump = false;
		// jump v+1 dist according to the example
		if(pos + v + 1 >= arr.size() || arr[pos+v+1] == 1){
			can_jump = true;
			helper(arr, v, pos+v+1, steps+1);
		}
		if(pos + v + 2 >= arr.size() || arr[pos+v+2] == 1){
			can_jump = true;
			helper(arr, v+1, pos+v+2, steps+1);
		}
		if(!can_jump)
			min_steps = -1;
	}
};

int main(){
	solution_fbjr *obj = new solution_fbjr();
	int a[] = {1,0,1,0,1};
	vector<int> arr (a, a+5);
	cout << obj->jumpRiver(arr) << endl;
	return 0;
}