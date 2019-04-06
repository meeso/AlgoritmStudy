#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
	vector<int> bridge;
	bridge.assign(bridge_length, 0);
	int truck_bottom = 0;
	int weight_of_bridge = 0;
       
	for (; truck_bottom < truck_weights.size(); answer++){
        if (weight_of_bridge - bridge.at(answer) + truck_weights.at(truck_bottom) <= weight){
			weight_of_bridge += truck_weights.at(truck_bottom);
			bridge.push_back(truck_weights.at(truck_bottom++));
		}
		else {
			bridge.push_back(0);
		}
		weight_of_bridge -= bridge.at(answer);
	}
    answer += bridge_length;
    return answer;
}
