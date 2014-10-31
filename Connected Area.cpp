/*
	Facebook Phone Interview
	1个2维的矩阵，里面都是0或者1， 给定一个坐标，让找到包含这个坐标点的连通域的面积。分recursive和iterative两种办法解。
	http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=107823&page=1#pid1491900
 */

#include<vector>
#include<iostream>
#include<queue>
using namespace std;
class solution_fbm {
public:
	int findConnectedArea(vector<vector<int>> &matrix, int x, int y){
		// x, y start from 0?
		int m = matrix.size();
		if(m == 0 || m <= x) return -1;
		int n = matrix[0].size();
		if(n <= y) return -1;
		
		vector<vector<int>> tmp = matrix; // save original matrix
		int dfs_ret = dfs(tmp, m, n, x, y, matrix[x][y]);

		cout << "dfs: " << dfs_ret << endl << endl;

		vector<vector<int>> tmp2 = matrix; // save original matrix
		int bfs_ret = bfs(tmp2, m, n, x, y, matrix[x][y]);

		cout << "bfs: " << bfs_ret << endl << endl;
		cout << "***********************************************" << endl << endl << endl;
		return 1;
	}

	int dfs(vector<vector<int>> &matrix, int m, int n, int x, int y, int cur){ // cur is either 0 or 1
		if(x < 0 || x >= m) return 0;
		if(y < 0 || y >= n) return 0;
		if(matrix[x][y] != cur) return 0;

		matrix[x][y] = cur == 0 ? 1 : 0;  // avoid loop
		cout << "(" << x << "," << y << ")" << endl;
		return 1 + dfs(matrix, m, n, x-1, y, cur) + 
			       dfs(matrix, m, n, x+1, y, cur) + 
				   dfs(matrix, m, n, x, y-1, cur) + 
				   dfs(matrix, m, n, x, y+1, cur);
	}

	int bfs(vector<vector<int>> &matrix, int m, int n, int x, int y, int cur){
		queue<int> q_x;
		queue<int> q_y;
		q_x.push(x);
		q_y.push(y);
		int count = 1;
		matrix[x][y] = cur == 0 ? 1 : 0; 
		
		while(!q_x.empty()){ // q_x && q_y should always have the same size
			queue<int> nt_q_x;
			queue<int> nt_q_y;
			while(!q_x.empty()){
				
				x = q_x.front();
				y = q_y.front();
				q_x.pop();
				q_y.pop();
				cout << "(" << x << "," << y << ")" << endl;
				
				if(x - 1 >= 0 && matrix[x-1][y] == cur){
					nt_q_x.push(x-1);
					nt_q_y.push(y);
					count++;
					matrix[x-1][y] = cur == 0 ? 1 : 0;  // would cause duplicate enqueue if flip when dequeue
				}
				if(y - 1 >= 0 && matrix[x][y-1] == cur){
					nt_q_x.push(x);
					nt_q_y.push(y-1);
					count++;
					matrix[x][y-1] = cur == 0 ? 1 : 0; 
				}
				if(x + 1 < m && matrix[x+1][y] == cur){
					nt_q_x.push(x+1);
					nt_q_y.push(y);
					count++;
					matrix[x+1][y] = cur == 0 ? 1 : 0; 
				}
				if(y + 1 < n && matrix[x][y+1] == cur){
					nt_q_x.push(x);
					nt_q_y.push(y+1);
					count++;
					matrix[x][y+1] = cur == 0 ? 1 : 0; 
				}
			}
			q_x = nt_q_x;
			q_y = nt_q_y;
		}
		return count;
	}
};

int main(){
	int a1[] = {0,0,1,0,0};
	int a2[] = {0,1,0,1,0};
	int a3[] = {0,1,0,1,0};
	int a4[] = {0,1,1,0,0};
	int a5[] = {0,1,1,0,0};
	vector<int> v1 (a1, a1+5);
	vector<int> v2 (a2, a2+5);
	vector<int> v3 (a3, a3+5);
	vector<int> v4 (a4, a4+5);
	vector<int> v5 (a5, a5+5);
	vector<vector<int>> matrix;
	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);
	matrix.push_back(v4);
	matrix.push_back(v5);

	solution_fbm *obj = new solution_fbm();
	obj->findConnectedArea(matrix, 2, 1);
	obj->findConnectedArea(matrix, 0, 4);
	return 0;
}




