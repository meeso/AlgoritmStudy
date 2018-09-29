#include <stdio.h>
#include <malloc.h>
#include <stack>
#include <queue>
using namespace std;
int n, m, v;
int **cnt;
int visit[1001];
stack<int> Stack;
queue<int> Queue;

void dfs_recursive(int v){
	visit[v] = 1;
	printf("%d ", v);
	for (int i = 1;i <= n; i++){
		if (cnt[v][i] == 1 && visit[i] != 1){
			dfs_recursive(i);
		}
	}
}
void dfs_stack(int v){
	Stack.push(v);
	visit[v] = 1;

	while (!Stack.empty()){
		v = Stack.top();
		Stack.pop();
		printf("%d ", v);
		for (int i = 1; i <= n; i++){
			if (cnt[v][i] == 1 && visit[i] == 0){
				Stack.push(i);
				visit[i] = 1;
				break;
			}
		}
	}
}
void bfs_queue(int v){
	Queue.push(v);
	visit[v] = 1;
	while (!Queue.empty()){
		v = Queue.front();
		Queue.pop();
		printf("%d ", v);
		for (int i = 1; i <= n; i++){
			if (cnt[v][i] == 1 && visit[i] == 0){
				Queue.push(i);
				visit[i] = 1;
			}
		}
	}
}
int main(){
	int tempI, tempJ, tempV;

	//Read number of node, edge, start node
	scanf("%d %d %d", &n, &m, &v);
	// Read connection Array
	cnt = (int**)malloc(sizeof(int*)*(n + 1));
	for (int i = 0; i < n + 1; i++){
		cnt[i] = (int*)malloc(sizeof(int)*(n + 1));
		visit[i+1] = 0;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			cnt[i][j] = 0;
	}
	for (int i = 1; i <= m; i++){
		scanf("%d %d", &tempI, &tempJ);
		cnt[tempI][tempJ] = 1;
		cnt[tempJ][tempI] = 1;
	}

	//DFS
	dfs_recursive(v);	
	printf("\n");

	//initialize VISIT Array
	for (int i = 1; i <= n; i++){
		visit[i] = 0;
	}
	
	//BFS
	bfs_queue(v);

	return 0;
}
