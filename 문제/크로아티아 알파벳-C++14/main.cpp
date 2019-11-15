//https://www.acmicpc.net/problem/2941
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> croatia = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main(int count, char *argv[]) {
	string s; cin >> s;
	count = s.size();

	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < croatia.size(); j++) {
			if (s[i] == croatia[j][0] && s[i+1] == croatia[j][1]) {
				if (j == 2) {
					if (s[i+2] == croatia[j][2]) {
						count -= 2;
						i += 2;
					}
					continue;
				}
				count--;
				i++;
			}
		}
	}

	cout << count;
	return 0;
}