//https://www.acmicpc.net/problem/10818
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> argc;

	int input, min = 1000000, max = -1000000;

	for (int i = 0; i < argc; i++) {
		cin >> input;
		if (input < min) min = input;
		if (input > max) max = input;
	}

	cout << min << ' ' << max;

	return 0;
}