//https://www.acmicpc.net/problem/10844
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int n, char *argv[]) {
	//input
	int k; cin >> n >> k;
	vector<int> values(n);
	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		values.push_back(input);
	}


	return 0;
}