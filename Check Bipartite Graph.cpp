/*
	Facebook Interview Question
	http://www.geeksforgeeks.org/bipartite-graph/
 */


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class solution_fbbg{
public:
	bool isBipartiteGraph(vector<vector<int>> &G, int src){
		int sz = G.size();

		// two colors: 0 and 1.  -1 refers no color
		vector<int> color(sz, -1);
		queue<int> q;
		q.push(src);
		color[src] = 0; // color '0'

		// bfs
		while(!q.empty()){

			int cur = q.front();
			q.pop();
			cout << "element: " << cur << ", color: " << color[cur] << endl;

			for(int i = 0; i < sz; ++i){
				if(i != cur && G[i][cur] != 0){ // check if they are connected in the graph
					// doesn't have a color
					if (color[i] == -1){
						color[i] = 1 - color[cur];
						q.push(i);
					}
					// has the same color
					else if(color[i] == color[cur]){
						return false;
					}
					// it is fine if the neighbor has a different color
				} 
			}
		}

		return true;
	}
};

int main(){
	solution_fbbg *obj = new solution_fbbg();
	int a1[] = {0, 1, 0, 1};
	int a2[] = {1, 0, 1, 0};
	int a3[] = {0, 1, 0, 1};
	int a4[] = {1, 0, 1, 0};
	vector<int>v1 (a1, a1+4);
	vector<int>v2 (a2, a2+4);
	vector<int>v3 (a3, a3+4);
	vector<int>v4 (a4, a4+4);
	vector<vector<int>> G;
	G.push_back(v1);
	G.push_back(v2);
	G.push_back(v3);
	G.push_back(v4);
	cout << obj->isBipartiteGraph(G, 0) << endl;
	return 0;
}