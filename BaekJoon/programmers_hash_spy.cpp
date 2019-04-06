#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
  	vector <vector <string>> hash (30, vector<string>(0));
	vector <string> key;

    int answer = 1;
    
	for (int i = 0; i < clothes.size(); i++){
		for (int k = 0; k <= key.size(); k++){
			if (key.size()==0){
				key.push_back(clothes[i][1]);
				hash[0].push_back(clothes[0][0]);
				break;
			}
			else if (k == key.size()){
				key.push_back(clothes[i][1]);
				hash[k].push_back(clothes[i][0]);
				break;
			}
			else if (key[k] == clothes[i][1]){
				hash[k].push_back(clothes[i][0]);
				break;
			}
			
		}
	}
	
	for (int i = 0; i < key.size(); i++){
		answer *= (hash[i].size()+1);
	}

    return answer-1;
}
