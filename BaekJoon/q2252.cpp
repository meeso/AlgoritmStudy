#include <stdio.h>
#include <malloc.h>
#include <queue>
using namespace std;

int main(){

	int N;  // 학생 수 N(1≤N≤32, 000):
	int M;  // 비교 횟수 M(1≤M≤100, 000)
	int from, to; //from -> to 순서로 서야함
	int *indegree;
	int i;
	int *visit;
	queue<int> Queue;
	vector <int> adj[32001];

	scanf("%d %d", &N, &M);

	indegree = (int*)malloc(sizeof(int)*(N + 1));
	//	visit = (int*)malloc(sizeof(int)*N);

	for (i = 0; i < N + 1; i++){
		indegree[i + 1] = 0;
		//		visit[i ] = 0;
	}

	for (i = 0; i < M; i++){
		scanf("%d %d", &from, &to);
		adj[from].push_back(to);
		indegree[to]++;
	}
	for (i = 1; i <= N; i++){
		if (indegree[i] == 0)
			Queue.push(i);
	}
	int v;
	vector<int>::iterator iter;

	while (!Queue.empty()){
		v = Queue.front();

		for (iter = adj[v].begin(); iter != adj[v].end(); iter++){
			if (--indegree[*iter] == 0){
				Queue.push(*iter);
			}
		}
		Queue.pop();
		//	visit[v - 1] = 1;
		printf("%d ", v);
	}
	return 0;
}

