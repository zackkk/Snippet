/*
	Facebook Interview Question

	Find the seond most common number in an array, return the frequency.
 */

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class solution_fbsmfn{
public:
	int secondMostFrequentNumber(vector<int> &arr){
		int first_value = 0;
		int first_times = INT_MIN;
		int second_value = 0;
		int second_times = INT_MIN;

		map<int, int> mymap;
		for(int i : arr){
			mymap[i]++;
			if(mymap[i] > first_times){
				first_value = i;
				first_times = mymap[i];
			}
			// the test case would cause a bug if use one loop
		}

		for(auto it = mymap.begin(); it != mymap.end(); ++it){
			if(it->first != first_value && it->second > second_times){
				second_value = it->first;
				second_times = it->second;
			}
		}

		cout << second_value << " " << second_times << endl;
		return 0;
	}
};

int main(){
	solution_fbsmfn *obj = new solution_fbsmfn();
	int a[] = {5, 5, 20, 20, 20, 10};
	vector<int> arr (a, a+6);
	obj->secondMostFrequentNumber(arr);
	return 0;
}