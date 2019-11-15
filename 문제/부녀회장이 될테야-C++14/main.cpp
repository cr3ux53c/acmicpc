//https://www.acmicpc.net/problem/2775
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int n, char* argv[]) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	// 0Ãþ ÃÊ±âÈ­
	vector<vector<int>> arr = vector<vector<int>>(14, vector<int>(14));
	for (int i = 0; i < 14; i++) {
		arr[0][i] = i + 1;
	}


	for (int i = 0; i < n; i++) {
		int k, n;
		cin >> k >> n;


	}

	return 0;
}