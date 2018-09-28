//https://www.acmicpc.net/problem/1005
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> buildTime;
vector<int> dp;
vector<vector<int>> order;
int n, k, w;

int calc(int w) {
	//baseCase
	if (dp[w] != 0)
		return dp[w];
	//calc
	int result = 0;
	for (int x = 0; x < n; x++) {
		if (order[x][w] == 1) {
			result = max(result, calc(x));
		}
	}
	return dp[w] = result + buildTime[w];
}

int main(int t) {
	cin >> t;

	//testCase
	for (int i = 0; i < t; i++) {
		buildTime = vector<int>(1001, 0);
		dp = vector<int>(1001, 0);
		order = vector<vector<int>>(1000, vector<int>(1000));

		//input
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> buildTime[i];
		for (int i = 0; i < k; i++) {
			int x, y; cin >> x >> y;
			order[x][y] = 1;
		}

		cin >> w;
		cout << calc(w) << '\n';
	}
	return 0;
}
