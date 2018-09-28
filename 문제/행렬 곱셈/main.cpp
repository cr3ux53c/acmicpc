//https://www.acmicpc.net/problem/2740
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

enum MATRIX {A, B};
vector<vector<vector<int>>> matrix(100, vector<vector<int>>(100, vector<int>(100, INT32_MAX)));
vector<vector<int>> result;

int main(int argc, char* args[]) {
	//init
	int n, m, k;
	//input
	for (int AB = A; AB <= B; AB++) { //matrix A, B ÃÑ µÎ¹ø µ¿¾È
		int a, b; cin >> a >> b;
		if (AB == A) {
			n = a; m = b;
		} else k = b;
		for (int i = 0; i < a; i++) {
			//matrix[AB].push_back(vector<int>(0));
			for (int j = 0; j < b; j++) {
				int input; cin >> input;
				matrix[AB][i][j] = input;
			}
		}
	}
	//calc
	result = vector<vector<int>>(n, vector<int>(k));

	for (int iii = 0; iii < n; iii++) {
		for (int ii = 0; ii < k; ii++) {
			int sum = 0;
			for (int i = 0; i < m; i++)
				sum += matrix[A][iii][i] * matrix[B][i][ii];
			result[iii][ii] = sum;
		}
	}
	//output
	for (auto i : result) {
		for (auto j : i)
			cout << j << " ";
		cout << "\n";
	}

	return 0;
}