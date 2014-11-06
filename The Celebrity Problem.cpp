/*
	Facebook Interview Question

	In a party of N people, only one person is known to everyone. 
	Such a person may be present in the party, if yes, (s)he doesn’t know anyone in the party. 
	We can only ask questions like “does A know B? “. Find the stranger (celebrity) in minimum number of questions.
 */

// O(n^2):
//		record indegree[i] & outdegree[i] of all persons, O(n^2)
//		the celebrity is the person with (indegree = n-1 && outdegree = 0)
// O(n):
//		compare two people, eliminate non-candidates:
//			1. they know each other:       both of them are not candidates
//			2. they don't know each other: both of them are not candidates
//			3. A knows B:				   A can't be a candidate
//		can eliminate one person in one comparasion
//		*check the final candidate

#include<iostream>
#include<stack>
using namespace std;
class theCelebrityProblem{
public:
	// assume N is greater than 2
	int findTheCelebrity(bool matrix[4][4], int N){
		stack<int> stk;
		for(int i = 0; i < N; i++)
			stk.push(i); // person 'i'
		
		while(stk.size() > 1){
			int a = stk.top(); // person 'a'
			stk.pop();
			int b = stk.top(); // person 'b'
			stk.pop();

			if(matrix[a][b] == matrix[b][a]){ 
				// they both know or don't know each other
			}
			else if(matrix[a][b] == 1){
				stk.push(b);
			}
			else
				stk.push(a);
		}

		if(stk.empty()) return -1;

		int candidate = stk.top();
		stk.pop();
		for(int i = 0; i < N; i++){
			if(i != candidate){
				// someone doesn't know him or he knows somebody
				if((matrix[i][candidate] != 1) || (matrix[candidate][i] == 1))
					return -1;
			}
		}
		return candidate;
	}
};

int main(){
	theCelebrityProblem *obj = new theCelebrityProblem();

	bool matrix[4][4] = {{0, 0, 0, 1}, 
						 {0, 0, 1, 1}, 
	                     {0, 0, 0, 1}, 
	                     {0, 0, 0, 0}};
	cout << obj->findTheCelebrity(matrix, 4) << endl;
	return 0;
}