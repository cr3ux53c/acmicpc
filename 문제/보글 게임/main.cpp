//https://algospot.com/judge/problem/read/BOGGLE
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
//const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };
const int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
char matrix[5][5];

bool hasWord(int y, int x, string word) {
	//baseCase
	if (word[0] != matrix[y][x])
		return false;
	if (word.size() == 1) {
		cout << "TRUE";
		return true;
	}
	//calc
	bool isNext = false;
	for (int i = 0; i < 8; i++) {
		if (hasWord(y + dy[i], x + dx[i], word.substr(1, 1))) {
			isNext = true;
		}
	}
	if (isNext) {

	}
}

int main(int t, char *argv[]) {
	cin >> t;
	//testCase
	for (int i = 0; i < t; i++) {
		vector<string> word;
		//input
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				cin >> matrix[j][k];
		int n; cin >> n;
		word = vector<string>(n);
		for (int j = 0; j < n; j++)
			cin >> word[j];
		
		//calc
		for (auto s : word) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					if (matrix[j][k] == s[0])
						cout << s << (hasWord(j, k, s) ? "YES" : "NO") << "\n";
				}
			}
		}
	}
	return 0;
}