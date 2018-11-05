#include <stdio.h>
#include <vector>
#include <utility>
#include <functional>
#include <queue>
#define INF 2147483647 
           
using namespace std;
int main(){
	//(1≤V≤20,000, 1≤E≤300,000) 
	int v, e;
	//우선순위 큐
	
	priority_queue <pair <int, int>> pq;
	//시작정점 K (1<=K<=V)
	int k;
	scanf("%d %d", &v, &e);
	scanf("%d", &k);
	//인접행렬 adj
	vector <vector <pair<int, int>>> adj;	
	adj.resize(v + 1);
	//distance 행렬
	int dist[20001], visit[20001];
	for (int i = 0; i < 20001; i++){
		dist[i] = INF;
		visit[i] = 0;
	}
	
	//u,v,w 을 통해 adj 행렬 입력
	int temp_u, temp_v;
	int temp_w;
	for (int i=0; i < e; i++){
		scanf("%d %d %d", &temp_u, &temp_v, &temp_w);
		adj[temp_u].push_back(make_pair(temp_w, temp_v));
	}
	//시작정점
	dist[k] = 0;
	pair<int, int> temp;
	pq.push(make_pair(0, k));
	while (!pq.empty()){
		temp = pq.top();
		pq.pop();
		temp_u = temp.second;
		temp_w = -temp.first;
		//printf("U: %d Weight : %d\n", temp_u, temp_w);
		
		if (dist[temp_u] < temp_w)
			continue;
			
		for (int i = 0; i < adj[temp_u].size();i++){
		//	printf("adj size: %d\n", adj[temp_u].size());
			int next_node = adj[temp_u].at(i).second;
			int next_cost = adj[temp_u].at(i).first;
			if (dist[next_node] > next_cost + temp_w){
				dist[next_node] = next_cost + temp_w;
				pq.push(make_pair(-dist[next_node], next_node));
	//			printf("new distance : %d, node :%d\n", dist[next_node], next_node);
			}
		}
	}
	
	for (int i = 1; i <= v; i++){
		if (dist[i] != INF)		
			printf("%d\n", dist[i]);
		else 
			printf("INF\n");
	}
	return 0;
}
