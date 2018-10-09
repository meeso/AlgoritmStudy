#include <stdio.h>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

int main(){
	priority_queue <unsigned long long int, 
		vector<unsigned long long int>, 
		greater <unsigned long long int>> pq;
	int k, n; // k개의 소수로 만든 N번째 숫자 출력하는것이 문제
	int sosu[100]; //입력 받은 소수들
	unsigned long long int temp_minor;

	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; i++){
		scanf("%d", &sosu[i]);  //받은 소수들 배열에 입력
		//push to priority Queue
		pq.push(sosu[i]);
	}

	for (int i = 1; i <= n;i++){
		//pop the minor value from the Queue
		temp_minor = pq.top();
		pq.pop();
		//push to priority Queue
		for (int j = 0; j < k; j++){
			pq.push(temp_minor*sosu[j]);
			if (temp_minor%sosu[j] == 0)
				break;
		}
		if (i == n)printf("%d", temp_minor);
	}

	return 0;
}
