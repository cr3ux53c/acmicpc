//https://algospot.com/judge/problem/read/BOGGLE
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
char matrix[5][5];

bool hasWord(int y, int x, string word) {
	//baseCase
	if (word[0] != matrix[y][x])
		return false;
	if (word.size() == 1) {
		return true;
	}
	//calc
	bool isNext = false;
	for (int i = 0; i < 8; i++) {
		if (hasWord(y + dy[i], x + dx[i], word.substr(1, word.size()))) {
			return true;
		}
	}
}

int main(int t, char *argv[]) {
	cin >> t;
	//testCase
	for (int i = 0; i < t; i++) {
		vector<string> words;
		//input
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				cin >> matrix[j][k];
		int n; cin >> n;
		words = vector<string>(n);
		for (int j = 0; j < n; j++)
			cin >> words[j];
		
		//calc
		for (auto s : words) {
			//¸Ê ÀüÃ¼ °Ë»ö
			bool isYes = false;
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					if (matrix[j][k] == s[0] && hasWord(j, k, s))
						isYes = true;
				}
			}
			cout << s << " " << (isYes ? "YES" : "NO") << "\n";
		}
	}
	return 0;
}