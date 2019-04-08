#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> answer_temp;
	
	for (int i = 0; i < progresses.size(); i++){
		int ans = (100 - progresses[i]) / speeds[i];
		if (((100 - progresses[i]) % speeds[i]) != 0) ans++;
	
		answer_temp.push_back(ans);
	}

	int max = 0;
	int k = 1;
	for (int i = 0; i <= progresses.size(); i++){
		if (i == 0){
			max = answer_temp[i];
		}
		else if (i == progresses.size())
			answer.push_back(k);
		else if (answer_temp[i] > max){
			max = answer_temp[i];
			answer.push_back(k);
			k = 1;
		}
		else{
			k++;
		}
	}

    return answer;
}
