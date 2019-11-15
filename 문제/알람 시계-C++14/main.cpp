//https://www.acmicpc.net/problem/2884
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int h, m;
	cin >> h >> m;

	if (m >= 45) {
		cout << h << ' ' << m - 45;
	} else {
		if (h >= 1) {
			cout << h - 1 << ' ' << 60 - abs(m - 45);
		} else {
			cout << 23 << ' ' << 60 - abs(m - 45);
		}
	}

	return 0;
}