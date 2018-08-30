//https://www.acmicpc.net/problem/5054
#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int sum = 0;
		for (int j = 0; j < n; j++) {
			int input;
			cin >> input;
			sum += input;
		}
		cout << sum / n << '\n';
	}
	return 0;
}