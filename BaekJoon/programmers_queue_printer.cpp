#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
   	int bottom = 0;

 	int size_of_queue = priorities.size();
	
	while (size_of_queue >= 0){
		int temp_j = priorities[bottom];
		for (int i = bottom; i < (bottom+size_of_queue); i++){
			if (i == (bottom + size_of_queue -1)){
				answer++;
				if (bottom == location){
					return answer;
				}
				size_of_queue--;
				bottom++;
			}
			else if (temp_j < priorities[i+1]){
				if (location == bottom)
					location += size_of_queue;
				bottom++;
				priorities.push_back(temp_j);
				break;
			}
		}
	}


    return answer;
}
