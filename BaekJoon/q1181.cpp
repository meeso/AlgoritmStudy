#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
bool compare(string a, string b){
	if (a.size() != b.size())
		return a.size() < b.size();
	else
		return a < b;
}
int main(){
	int n;
	string temp;

	vector <string> answer;
	vector<string> operations;
	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> temp;
		operations.push_back(temp);
	}

	sort(operations.begin(), operations.end(), compare);
	
	string temp1;
	for (int i = 0; i < operations.size(); i++){
		if (temp1 == operations[i]) continue;
		else{
			temp1 = operations[i];
			cout << operations[i] << '\n';
		}
	}

	return 0;
}
