/*
 Well-ordered string means that the order of the characters is in an alphabetical increasing order.
 Like abEm is a well-ordered number. However, abmE is not a well-order number. 
 Givenan input # that tells you also how many digits are in the password, print allpossible passwords.
 */

// upper-case / lower-case

#include<vector>
#include<iostream>
using namespace std;
class solution_wos {
public:
	void wellOrderedString(int n){
		vector<char> v;
		dfs(n, 'a', v);
	}

	void dfs(int n, char cur, vector<char> &v){
		if(v.size() == n){
			for(char c : v)
				cout << c;
			cout << endl;
			return;
		}

		for(char c = cur; c <= 'z'; c++){
			v.push_back(c);
			dfs(n, c+1, v);
			v.pop_back();

			char cc = c - 'a' + 'A';
			v.push_back(cc);
			dfs(n, c+1, v);
			v.pop_back();
		}
	}
};


int main(){
	solution_wos *obj = new solution_wos();
	obj->wellOrderedString(2);
	return 0;
}