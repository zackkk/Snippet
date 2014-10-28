/*
	Print steps of doing swap
	You can swap only two consecutive elements. 
	You have to show all steps to convert a string into another string (both strings will be anagrams of each other). 
	E.g. GUM to MUG
	GUM
	GMU
	MGU
	MUG
 */

// BFS

#include<string>
#include<map>
#include<queue>
#include<iostream>
using namespace std;
class solution_swap{
public:
	void printSwapSteps(string &src, string &dest){
		map<string, queue<string>> paths;  // store path for all strings

		// path for src
		queue<string> cur;
		cur.push(src);
		paths[src] = cur;

		while(!cur.empty()){
			queue<string> next;

			while(!cur.empty()){
				string str = cur.front();
				cur.pop();
				if(str == dest){
					printPath(paths[str]);
					return;
				} 

				// generate the next level in bfs
				for(int i = 0; i < str.size() - 1; i++){
					string tmp = str;
					swap(tmp, i, i+1);
					if(paths[tmp].empty()){
						queue<string> tmp_queue = paths[str];
						tmp_queue.push(tmp);
						paths[tmp] = tmp_queue;
						next.push(tmp);
					}
				}
			}

			cur = next;
		}
	}

	void swap(string &str, int i, int j){
		char c = str[i];
		str[i] = str[j];
		str[j] = c;
	}

	void printPath(queue<string> &path){
		while(!path.empty()){
			string str = path.front();
			cout << str << endl;
			path.pop();
		}
	}
};

int main(){
	solution_swap *obj = new solution_swap();
	string src = "GUM";
	string dest = "MUG";
	obj->printSwapSteps(src, dest);
	return 0;
}