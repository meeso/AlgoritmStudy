#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
	return a > b;
}
int solution(vector<int> citations) {
    int answer = 0;
	int count =0;
    
	sort(citations.begin(), citations.end(), compare);

	for (answer = citations[0]; answer >= count; answer--){
			while (citations[count] == answer){
			count++;
            }
	}
    return answer+1;
}
