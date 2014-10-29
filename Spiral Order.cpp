/*
	If an N X N matrix is given, print it in spiral order. 
	Example: Below is 5 X 5 matrix 

	i l o v e 
	d i n t e  
	n e w e p 
	a i v r i 
	m a x e c 

	Print in spiral order. Output is iloveepicexamandinterview
 */

#include<vector>
#include<string>
#include<iostream>
using namespace std;
class solution_so {
public:
	void printSpiralOrder(vector<vector<char>> &matrix, int N){
		vector<vector<bool>> visited (N, vector<bool> (N, false));

		string str = "";
		str += matrix[0][0];
		visited[0][0] = true; // bug happened here
		int i = 0;
		int j = 0;
		int k = 1;
		
		while(k < N*N){
			// go right
			while(j + 1 < N && visited[i][j+1] == false){
				str += matrix[i][j+1];
				visited[i][j+1] = true;
				j++;
				k++;
			}
			// go down
			while(i + 1 < N && visited[i+1][j] == false){
				str += matrix[i+1][j];
				visited[i+1][j] = true;
				i++;
				k++;
			}
			// go left
			while(j - 1 >= 0 && visited[i][j-1] == false){
				str += matrix[i][j-1];
				visited[i][j-1] = true;
				j--;
				k++;
			}
			// go up
			while(i - 1 >= 0 && visited[i-1][j] == false){
				str += matrix[i-1][j];
				visited[i-1][j] = true;
				i--;
				k++;
			}
		}
		cout << str << endl;
	}
};

int main(){
	char c1[] = {'i', 'l', 'o', 'v', 'e'};
	char c2[] = {'d', 'i', 'n', 't', 'e'};
	char c3[] = {'n', 'e', 'w', 'e', 'p'};
	char c4[] = {'a', 'i', 'v', 'r', 'i'};
	char c5[] = {'m', 'a', 'x', 'e', 'c'};
	vector<char> v1;
	vector<char> v2;
	vector<char> v3;
	vector<char> v4;
	vector<char> v5;
	v1.assign(c1, c1+5);
	v2.assign(c2, c2+5);
	v3.assign(c3, c3+5);
	v4.assign(c4, c4+5);
	v5.assign(c5, c5+5);
	vector<vector<char>> matrix;
	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);
	matrix.push_back(v4);
	matrix.push_back(v5);

	solution_so *obj = new solution_so();
	obj->printSpiralOrder(matrix, 5);
	return 0;
}