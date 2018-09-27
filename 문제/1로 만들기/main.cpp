//https://www.acmicpc.net/problem/1463
#include <iostream>
#include <string>
using namespace std;

int dp[1000001];

int main(int n, char *argv[]) {
	cin >> n;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = (dp[i] < dp[i / 2] + 1) ? dp[i] : dp[i / 2] + 1;
		if (i % 3 == 0)
			dp[i] = (dp[i] < dp[i / 3] + 1) ? dp[i] : dp[i / 3] + 1;
	}

	cout << dp[n];

	return 0;
}