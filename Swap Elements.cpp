
#include<iostream>
#include<vector>
using namespace std;

class solution_fbse{
public:
	int swapElements(vector<int> &arr){
		int slow = 0;
		for(int fast = 0; fast < arr.size(); fast++){
			if(arr[fast] != 0){
				arr[slow] = arr[fast];
				slow++;
			}
		}
		int ret = slow;
		for( ; slow < arr.size(); slow++) arr[slow] = 0;
		return ret;
	}
};

int main(){
	solution_fbse *obj = new solution_fbse();
	int a[] = {0,0,0,1,2,3,-1,0,0,1};
	vector<int> arr (a, a+10);
	cout << obj->swapElements(arr) << endl;
	for(int i : arr) cout << i << " ";
	return 0;
}