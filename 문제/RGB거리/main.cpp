//https://www.acmicpc.net/problem/1149
#include <iostream>
#include <string>
using namespace std;

int cost[1000][3];

int main(int n, char *argv[]) {
	cin >> n; 
	//input
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++){
			int input;
			cin >> input;
			cost[i][j] = input;
		}
	} 

	for (int i = 0; i < n; i++) {

	}

	return 0;
}