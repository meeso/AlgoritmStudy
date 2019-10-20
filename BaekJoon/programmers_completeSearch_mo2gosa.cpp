#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
	int num[10] = { 0 };
	// 1번 : 12345 
	//2번 : 21 23 24 25 
	//3번 : 33 11 22 44 55 

	vector<int> answer_a = { 1, 2, 3, 4, 5 };
	vector<int> answer_b = { 2, 1, 2, 3, 2, 4, 2, 5 };
	vector<int> answer_c = { 3,3,1,1,2,2,4,4,5,5 };

	int max = 0;
	for (int i = 0; i < answers.size(); i++){
		if (answer_a[i%5] == answers[i]) 
			num[0]++;
		if (answer_b[i%8] == answers[i]) 
			num[1]++;
		if (answer_c[i%10] == answers[i]) 
			num[2]++;
		if (max <= num[0]) max = num[0];
		if (max <= num[1]) max = num[1];
		if (max <= num[2]) max = num[2];

	}
		if (max == num[0]) answer.push_back(1);
		if (max == num[1]) answer.push_back(2);
		if (max == num[2]) answer.push_back(3);

    
    return answer;
}
