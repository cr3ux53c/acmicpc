//https://www.acmicpc.net/problem/1932
#include <iostream>
#include <string>
using namespace std;

int map[500][500];

int main(int t, char *argv[]) {
	//init
	int result = 0;
	
	//input
	cin >> t;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j <= i; j++) {
			int input;
			cin >> input;
			map[i][j] = input;
		}
	}

	//calc
	for (int i = 0; i < t; i++)
		for (int j = 0; j <= i; j++)
			map[i][j] = map[i][j] + map[i - 1][j - 1] > map[i][j] + map[i - 1][j] ? map[i][j] + map[i - 1][j - 1] : map[i][j] + map[i - 1][j];
	
	//findMax
	for (int i = 0; i < t; i++)
		if (map[t - 1][i] > result) result = map[t - 1][i];
	cout << result;
	return 0;
}