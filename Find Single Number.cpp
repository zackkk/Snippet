/*
	Facebook Interview Question
	Find the single number in a sorted array in O(logn) time.
 */

// basic idea: O(logn) should use binary search
// target partition should have odd size
// two cases:
//		mid is odd / even 

#include<iostream>
#include<vector>
using namespace std;

class solution_fbfsn{
public:
	int findSingleNumber(vector<int> &arr){
		int start = 0;
		int end = arr.size() - 1;
		while(start <= end){
			int mid = start + (end - start) / 2;

			if(mid == start && mid == end)
				return arr[mid];

			// mid at odd position (starts from 0)
			if(mid % 2 == 0){
				if(arr[mid] == arr[mid+1])
					start = mid + 2;
				else if(arr[mid] == arr[mid-1])
					end = mid - 2;
				else
					return arr[mid];
			}
			// mid at even position 
			else{
				if(arr[mid] == arr[mid+1])
					end = mid - 1;
				else if(arr[mid] == arr[mid-1])
					start = mid + 1;
				else
					return arr[mid];
			}
		}
		return -1;
	}
};

int main(){
	solution_fbfsn *obj = new solution_fbfsn();
	int a[] = {1,1,3,4,4,5,5};
	vector<int> arr(a, a+7);
	cout << obj->findSingleNumber(arr) << endl;
	return 0;
}