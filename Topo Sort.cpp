/* 
 *	In a Directed-Acylic Graph, maintain three data structures:
 *		1. adjacency matrix in which a node has all "approachable" nodes.
 *		2. an array stores the number of "come in" nodes [degree]
 *		3. stack of elements with zero degree
 */


// the following code hasn't been tested, but it described the algorithm well.

#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Description: 表示图的结点的邻接边
struct Edge{
	int dest;
	Edge *next;
} **graph;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Description: 添加一个边
// Input: e - 要添加边的结点, p - 目的地 
// Output: e - 添加边后的结点
void AddEdge(Edge *&e, int p) {
	if(!e){
		e = new Edge;
		e->dest = p;
		e->next = 0;
	}
	else{
		Edge *tail = e;
		while (tail->next) tail = tail->next;
		tail->next = new Edge;
		tail = tail->next;
		tail->dest = p;
		tail->next = 0;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Description: 输入结点之间的边
// Input: Console下用户输入,起点和终点; m - 边的个数
// Output: graph - 图;
void Input(int &m){
	int i, a, b;	// a->b存在边(有向)
	for (i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		AddEdge(graph[a], b);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Description: 获得每个结点的入度
// Input: n - 结点的个数
// Output: degree - 每个结点的入度
void GetDegree(int *degree, int n) {
	int i = 0;
	Edge *edge;

	memset(degree, 0, sizeof(int) * n);
	for (i = 0; i < n; i++) {
		edge = graph[i];
		while(edge) {
			degree[edge->dest]++;
			edge = edge->next;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Description: 拓扑排序
// Input: n - 结点个数
// Output: console下输出一个正确的拓扑序
void TopoSort(int n) {
	int *degree = new int[n]; // 初始化所有结点的入度
	GetDegree(degree, n);

	stack<int> s;             // 获得入度为0的结点,并入栈
	int i = 0;																			
	for (i = 0; i < n; i++)
		if (degree[i] == 0)
			s.push(i);

	int index = 0;			  // 结点的下标
	Edge *edge;				  // 当前结点邻接表(adjacency matrix)
	while (!s.empty()) {
		index = s.top();
		printf("%d", index);
		s.pop();

		edge = graph[index];  // get the linked list
		while (edge){
			if (--degree[edge->dest] == 0)
				s.push(edge->dest);
			edge = edge->next;
		}
	}

	delete []degree;
}

int main() {
	int n, m;	// 结点个数、边个数
	scanf("%d %d", &n, &m);

	int i;
	graph = new Edge*[n];
	for(i = 0; i < n; i++) graph[i] = 0;

	Input(m);
	TopoSort(n);

	return 0;
}