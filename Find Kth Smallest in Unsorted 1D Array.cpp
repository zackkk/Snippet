/*
	Facebook Interview Question
	Find the kth smallest element in an array having n elements?
		Min Heap, need extra space
		Quick Select (idea comes from quick sort). Worst O(n^2), Average O(n)
 */

#include<iostream>
#include<vector>
using namespace std;

class solution_fbqs{
public:
	int findKthSmallest(vector<int> &arr, int k){
		if(k > arr.size()) k = k % arr.size();
		return helper(arr, k, 0, arr.size()-1);
	}

	int helper(vector<int> &arr, int k, int low, int high){
		if(low > high) return -1;
		int pivot = arr[low];
		int i = low;
		int j = high;
		while(i < j){
			while(i < j && arr[j] >= pivot) // ">="
				j--;
			while(i < j && arr[i] <= pivot)
				i++;
			if(i < j)
				swap(arr, i, j);
		}
		arr[low] = arr[i];
		arr[i] = pivot;
		
		// (i - low + 1) is the number of elements between low and i

		if(i - low + 1 == k) 
			return pivot;
		else if(i - low + 1 < k)
			return helper(arr, k - (i - low + 1), i+1, high);
		else
			return helper(arr, k, low, i-1);
	}

	void swap(vector<int> &arr, int i, int j){
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
};

int main(){
	solution_fbqs *obj = new solution_fbqs();
	int a[] = {5,1,6,4,2,3};
	vector<int> arr (a, a+6);
	cout << obj->findKthSmallest(arr, 1) << endl;
	cout << obj->findKthSmallest(arr, 2) << endl;
	cout << obj->findKthSmallest(arr, 3) << endl;
	cout << obj->findKthSmallest(arr, 4) << endl;
	cout << obj->findKthSmallest(arr, 5) << endl;
	cout << obj->findKthSmallest(arr, 6) << endl;
	return 0;
}