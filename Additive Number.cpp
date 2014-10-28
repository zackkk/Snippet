/*
	An additive sequence is 1,2,3,5,8,13 
	where T(n) = T(n-1) + T(n-2) 

	An additive sequence number is which when splitted in two different number forms additive seq. 
	Ex: 1235813 (split it 1,2,3,5,8,13) 
	Ex: 12122436(12,12,24,36) 

	A number range is given to you. Find the additive sequence number in that range.
 */

// INT_MAX: 2^15-1 = 32767
// LONG_MAX: 2^31-1 = 2147483647
// Max number of digit: 3


#include<vector>
#include<string>
#include<iostream>
using namespace std;
class solution_an {
public:
	bool isAdditiveNumber(long n){
		for(int digit = 1; digit <= 3; digit++){
			vector<int> sequence;
			splitNumber(digit, n, sequence);
			if(checkSequence(sequence)) 
				return true;
		}
		return false;
	}

	void splitNumber(int len, long n, vector<int> &sequence){
		cout << "splitting " << n  << " into " << len << " digits: " << endl;

		string str = to_string(n);
		int i = 0; // string index
		while(i < str.size()){
			int num = 0;
			if(str.size() - i < len){  // corner case: e.g. 5 -> 8 -> 13 -> 2
				num = stoi(str.substr(i));
			}
			else{
				num = stoi(str.substr(i, len));
				int sz = sequence.size();
				if(sz > 0 && sequence[sz-1] > num){  // need increase the number of digit, e.g. 8 -> 13
					len++;
					num = stoi(str.substr(i, len));
				}
			}
			cout << num << endl;
			sequence.push_back(num);
			i += len;
		}
	}

	bool checkSequence(vector<int> &sequence){
		if(sequence.size() < 3) return false;
		for(int i = 2; i < sequence.size(); i++){  // bug here: used i = 3
			if(sequence[i] != sequence[i-1] + sequence[i-2]) 
				return false;
		}
		return true;
	}

	void printInfo(long n){
		if(isAdditiveNumber(n)) 
			cout << "*****" << n << " is additive number." << "*****"<< endl << endl;
		else
			cout << "*****" << n << " is not additive number." << "*****" << endl << endl;
	}
};

int main(){
	solution_an *obj = new solution_an();
	obj->printInfo(1235813);
	obj->printInfo(12358132);
	obj->printInfo(12122436);
	obj->printInfo(121224345);
	return 0;
}
