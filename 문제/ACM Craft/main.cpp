//https://www.acmicpc.net/problem/1005
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> buildTime;
vector<int> dp;
vector<vector<int>> order;
int n, k, target;

int getMax(int target, int b) {
	return target > b ? target : b;
}

int calc(int target) {
	if (dp[target] != 0) {
		return dp[target];
	} else {
		int result = 0;
		for (int i = 1; i <= n; i++) {
			if (order[target][i] == 1) {
				result = getMax(result, calc(i));
			}
		}
		return dp[target] = result + buildTime[target];
	}
}

int main(int t) {
	cin >> t;

	//testCase
	for (int i = 0; i < t; i++) {
		buildTime = vector<int>(1001, 0);
		dp = vector<int>(1001, 0);
		order = vector<vector<int>>(1001, vector<int>(1001));

		//input
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> buildTime[i];
		for (int i = 0; i < k; i++) {
			int target, b; cin >> target >> b;
			order[b][target] = 1;
		}
		cin >> target;

		cout << calc(target) << '\n';
	}
	return 0;
}
