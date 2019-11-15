//https://www.acmicpc.net/problem/2562
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<int> v;

	for (int i = 0; i < 9; i++) {
		int input;
		cin >> input;
		v.push_back(input);
	}

	int max = -1;
	int maxIdx;
	for (int i = 0; i < v.size(); i++) {
		if (max < v[i]) {
			max = v[i];
			maxIdx = i;
		}
	}
	cout << max << "\n" << maxIdx+1;
	return 0;
}