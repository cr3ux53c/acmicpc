//https://algospot.com/judge/problem/read/JUMPGAME
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int c, char *argv[]) {
	//input
	cin >> c;
	//testCase
	for (int i = 0; i < c; i++) {
		int n; cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n));

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				int input; cin >> input;
				matrix[j][k] = input;
			}
		}
	}
	return 0;
}