//https://www.acmicpc.net/problem/1157
#include <iostream>
#include <string>
#include <vector>
using namespace std;

char s[1000001];

int main(int argc, char *argv[]) {
	cin >> s;
	vector<int> map(26, 0);
	
	for (int i = 0; i < 1000001;i++) {
		if (s[i] == NULL) break;
		int idx = toupper(s[i]);
		map[idx-65]++;
	}

	int maxNum = -1;
	int maxIndex = -1;
	for (int i = 0; i < map.size();i++) {
		if (map[i] > maxNum && map[i] > 0) { 
			maxNum = map[i];
			maxIndex = i;
		} else if (map[i] == maxNum) {
			cout << '?';
			return 0;
		}
	}
	cout << (char)(maxIndex+65);
	return 0;
}