/*
  Determine whether a number is colorful or not. 
  263 is a colorful number because (2,6,3,2x6,6x3,2x3x6) are all different; 
  236 is not because (2,3,6,2x3,3x6,2x3x6) have 6 twice. 
  So take all consecutive subsets of digits, take their product and ensure all the products are different
 */
#include<unordered_map>
#include<string>
#include<iostream>
using namespace std;
class solution_cn {
public:
	bool isColorfulNumber(long n){
		unordered_map<int, int> mymap; // <value, frequency>
		string str = to_string(n);
		for(int len = 1; len <= str.size(); len++){
			int i = 0;
			while(i + len <= str.size()){
				int num = stoi(str.substr(i, len)); // get the number of length "len"
				cout << num << endl;
				int sum = 1; // multiplication of all digits
				while(num != 0){
					sum *= (num % 10);  
					num /= 10;
				}
				if(mymap[sum]) return false;
				mymap[sum] = 1;
				i++;
			}
		}
		return true;
	}
};

int main(){
	solution_cn *obj = new solution_cn();
	cout << "263 " << obj->isColorfulNumber(263) << endl;
	cout << "236 " << obj->isColorfulNumber(236) << endl;
	return 0;
}