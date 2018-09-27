//https://www.acmicpc.net/problem/1149
//나중에 다시 시도
#pragma warning (disable:4996)
#include <iostream>
#include <string>
using namespace std;

int map[1001][3];

int main(int n, char *argv[]) {
	//init
	int result = 999999;
	//input
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d %d %d", &map[i][0], &map[i][1], &map[i][2]);
	//calc
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++)
			map[i][j] += map[i - 1][(j + 1) % 3] > map[i - 1][(j + 2) % 3] ? map[i - 1][(j + 2) % 3] : map[i - 1][(j + 1) % 3];
	for (int i = 0; i < 3; i++)
		result = map[n][i] > result ? result : map[n][i];
	cout << result;

	return 0;
}