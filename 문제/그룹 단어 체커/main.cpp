//https://www.acmicpc.net/problem/1316
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
	cin >> argc;
	int count = 0;

	for (int i = 0; i < argc; i++) {
		string s; cin >> s;
		vector<int> flag(26);
		for (int i = 0; i < s.size();i++) {
			if (flag[s[i] - 97] != -1)
				flag[s[i] - 97]++;
			else {
				count--;
				break;
			}
			if (s[i + 1] != s[i])
				flag[s[i] - 97] = -1;
		}
		count++;
	}

	if (count < 0) count = 0;
	cout << count;

	return 0;
}