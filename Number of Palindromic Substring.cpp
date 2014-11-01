/*
	Facebook interview question
	Given a string, return the number of palindromic substring
	e.g. abba, return 6;
 */

// dp, table size 2d

#include<vector>
#include<string>
#include<iostream>
using namespace std;
class solution_fbnps{
public:
	int numberOfPalindromicSubstring(string &str){
		int sz = str.size();
		if(sz == 0) return 0;

		int count = 0;

		// flag[i][j] == true iff str[i...j] is palindromic, i <= j
		vector<vector<bool>> flag (sz, vector<bool>(sz, false));

		// initialize
		for(int i = 0; i < sz; i++){ // length == 1
			flag[i][i] = true;
			count++;
		}
		for(int i = 0; i < sz-1; i++){ // length == 2
			if(str[i] == str[i+1]){
				flag[i][i+1] = true;
				count++;
			}
		}

		// others
		for(int len = 3; len <= sz; len++){
			for(int i = 0; i + len - 1 < sz; i++){
				if(str[i] == str[i+len-1] && flag[i+1][i+len-1-1]){
					flag[i][i+len-1] = true;
					count++;
				}
			}
		}

		return count;
	}
};

int main(){
	solution_fbnps *obj = new solution_fbnps();
	string str = "abba";
	cout << obj->numberOfPalindromicSubstring(str) << endl;
	return 0;
}
