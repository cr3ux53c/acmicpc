//https://www.acmicpc.net/problem/2579
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int n, char *argv[]) {
	//input
	cin >> n;
	vector<int> stair(n, -1);
	vector<int> dp(n, -1);
	for (int i = 0; i < n; i++)
		cin >> stair[i];

	//calc
	//prevent index overflow
	dp[0] = stair[0];
	dp[1] = max(stair[0] + stair[1], stair[1]);
	dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

	for (int i = 3; i < n; i++)
		dp[i] = max(dp[i - 2] + stair[i], stair[i - 1] + stair[i] + dp[i - 3]);

	cout << dp[n - 1];
	return 0;
}