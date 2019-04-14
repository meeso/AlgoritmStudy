#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
bool compare(vector<int> a, vector<int> b){
	if (a[0] == b[0]){
		return a[1] < b[1];
	}
	else return a[0] < b[0];
}
int solution(vector<vector<int>> jobs) {
    int answer = 0;
	priority_queue <int, vector<int>, greater<int>> pq;

	int iswork = 0;
	int total_working = 0;
	int total_starttime = 0;
	int j = 0;
	int a = jobs.size();

	sort(jobs.begin(), jobs.end(), compare);

	for (int time = 0; ((iswork!=0) || (a!=0)); time++){
			while (j < jobs.size() && time == jobs[j][0])
			{
				total_starttime += jobs[j][0];
				pq.push(jobs[j][1]);
				j++;
			}
		if (iswork == 0 && !pq.empty()){
			iswork = pq.top();
			total_working += (iswork+time);
			pq.pop();
			a--;
			if ( a== 0 )
				break;
		}
		if(iswork !=0)
			iswork--;
	}
	answer = (total_working-total_starttime) / jobs.size();

    return answer;
}
