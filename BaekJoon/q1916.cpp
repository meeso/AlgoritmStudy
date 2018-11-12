#include <stdio.h>
#include <queue>
#include <functional>
#include <vector>
#define INF 2147483647 
using namespace std;

int main(){
	int temp_a, temp_b, temp_w;
    int n, m;
	int dist[1001];
	int start, end;
	priority_queue <pair<int, int>> pq;
	scanf("%d", &n); //n개 정점
	scanf("%d", &m);

	//adj 배열. vector[1]에는 <1에서 이동한 지점, 무게> 가 들어있음
	vector<vector <pair<int, int>>> adj; 
	adj.resize(n + 1);

	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	for (int i = 0; i < m; i++){
		scanf("%d %d %d", &temp_a, &temp_b, &temp_w);
		adj[temp_a].push_back(make_pair(temp_w, temp_b));
	}
	scanf("%d %d", &start, &end);
	//출발점 push.
	dist[start] = 0;
	pq.push(make_pair(0, start));

	while (pq.empty() != true){
		int weight_of_start_v = -pq.top().first;
		temp_b = pq.top().second;
		pq.pop();

		for (int i = 0;i < adj[temp_b].size(); i++){
			int	weight_to_next_v = adj[temp_b].at(i).first;
			int next_vertex = adj[temp_b].at(i).second;
			if (dist[next_vertex] > weight_to_next_v + weight_of_start_v){
				dist[next_vertex] = weight_to_next_v + weight_of_start_v;
				pq.push(make_pair(-dist[next_vertex], next_vertex));
			}
		}
	}

	printf("%d", dist[end]);

	return 0;
}
