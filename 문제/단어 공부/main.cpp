//https://www.acmicpc.net/problem/1157
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	string s; cin >> s;
	vector<int> map(26, 0);
	
	//input
	for (char ch : s) {
		int i = toupper(ch);
		map[i-65]++;
	}
	
	//calc
	char result = '?';
	pair<char, int> count = { 'A', 0 };
	for (int i = 0; i < map.size(); i++) {
		if (map[i] > count.second) {
			result = count.first = i + 65;
			count.second = map[i];
		} else if (map[i] == count.second) {
			result = '?';
		}
	}

	cout << result;
	return 0;
}

//ABABCCC