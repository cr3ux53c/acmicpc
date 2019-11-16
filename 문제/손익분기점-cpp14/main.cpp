//https://www.acmicpc.net/problem/1712
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;

	if (B >= C) {
		cout << -1;
		return 0;
	}

	for (int i = 1;; i++) {
		if (A + B * i < C * i) {
			cout << i;
			return 0;
		}
	}

	return 0;
}