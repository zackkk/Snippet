/*
	Facebook Interview Question
	e.g. Given A B C D E F
			   2 5 4 3 0 1
	output:
		E F A D C B
 */

#include<iostream>
#include<vector>
using namespace std;
class solution_fbabc{
public:

	// swap until position i has its "desired" index 
	void swapWords(vector<char> &arr, vector<int> &index){
		for(int i = 0; i < arr.size(); ++i){
			while(index[i] != i)
				swap(arr, index, index[i], i);
		}
	}

	void swap(vector<char> &arr, vector<int> &index, int i, int j){
		char c = arr[i];
		arr[i] = arr[j];
		arr[j] = c;
		int k  = index[i];
		index[i] = index[j];
		index[j] = k;
	}
};

int main(){
	solution_fbabc *obj = new solution_fbabc();

	char a[] = {'A','B','C','D','E','F'};
	int  i[] = {2,5,4,3,0,1};
	vector<char> arr (a, a+6);
	vector<int> ii (i, i+6);
	obj->swapWords(arr, ii);
	for(char c : arr)
		cout << c << " ";
	return 0;
}