#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

bool cmp(const string &a, const string &b){
	string tmpAB = a + b;
	string tempBA = b + a;
	return atoi(tmpAB.c_str()) > atoi(tempBA.c_str());
}
string solution(vector<int> numbers) {
    string answer = "";
    	
    vector <string> string_number;

	for (int i = 0; i < numbers.size(); i++){
		string_number.push_back(to_string(numbers[i]));
	}
	sort(string_number.begin(), string_number.end(), cmp);
	for (int i = 0; i < string_number.size();i++){
		answer += string_number[i];
	}
    
	if (atoi(answer.c_str()) == 0) answer = "0";

    
	return answer;
}
