//https://www.acmicpc.net/problem/1932
#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> matrix;
vector<vector<int>> memo;
int t;
int result;
int sum;
		
int dp(int y, int x, int sum) {
	//cout << "(" << y << ", " << x << ") : " << matrix[y][x] << "\n";
	//baseCase
	if (y == t) {
		if (result < sum) result = sum;
		return sum;
	}
		
	sum += matrix[y][x];
	//memoization
	if (memo[y][x] != -1) {
		dp(y + 1, x, memo[y][x]);
	}
	memo[y][x] = sum;
	dp(y + 1, x, sum);
	if (y == 0 && x == 0) return -1;
	if (memo[y - 1][x] == -1) {
		return -1;
	}
	dp(y, x + 1, memo[y-1][x]);
	return -1;
}

int main(int argc, char *argv[]) {
	//string inputs = argv[1];
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		matrix.push_back(vector<int>(t, -1));
		memo.push_back(vector<int>(t, -1));
	}
	
	//input
	for (int i = 0; i < t; i++) {
		for (int j = 0; j <= i; j++) {
			int input;
			cin >> input;
			matrix[i][j] = input;
		}
	}
	
	dp(0, 0, 0);
	cout << result;
	return 0;
}