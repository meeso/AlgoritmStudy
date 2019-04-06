#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
          
	map <string, int> a;

	for (int i = 0; i < participant.size();i++){
		a[participant[i]]++;
	}
	for (int i = 0; i < completion.size(); i++){
		a[completion[i]]--;
	}

	for (int i = 0; i < participant.size(); i++){
		if (a[participant[i]] == 1) 
            answer = participant[i];
	}
    
    return answer;
}
