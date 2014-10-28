/*
	Print all valid phone numbers of length n subject to following constraints: 
	1.If a number contains a 4, it should start with 4 
	2.No two consecutive digits can be same 
	3.Three digits (e.g. 7,2,9) will be entirely disallowed, take as input 
*/

#include<vector>
#include<iostream>
using namespace std;
class solution_pn {
public:
	void printValidPhoneNumbers(vector<int> &digits, int n){
		vector<int> numbers;
		helper(n, numbers, digits);
	}

	void helper(int n, vector<int> &numbers, vector<int> &digits){
		if(numbers.size() == n){
			for(int i : numbers)
				cout << i;
			cout << endl;
			return;
		}

		for(int num = 0; num <= 9; num++){
			int sz = numbers.size();
			if(num == 4  && sz > 0)  // condition 1
				continue;
			if(sz > 0 && numbers[sz-1] == num) // condition 2
				continue; 
			if(find(digits.begin(), digits.end(), num) != digits.end()) // condition 3
				continue;

			numbers.push_back(num);
			helper(n, numbers, digits);
			numbers.pop_back();
		}
	}
}; 

int main(){
	solution_pn *obj = new solution_pn();
	vector<int> digits;
	digits.push_back(7);
	digits.push_back(2);
	digits.push_back(9);
	obj->printValidPhoneNumbers(digits, 3);
	return 0;
}

