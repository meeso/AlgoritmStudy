#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int count = 0;
	for (int i = 0; i < arrangement.size(); i++){
		if (arrangement.at(i) == '('){
			if (arrangement.at(i + 1) == ')'){
				
			}
			else {
				count++;
			}
		}
		else {
			if (i >= 1 && arrangement.at(i - 1) == '('){
				answer += count;
			}
			else {
				answer += 1;
				count--;
			}

		}
	}

    
    
    return answer;
}
