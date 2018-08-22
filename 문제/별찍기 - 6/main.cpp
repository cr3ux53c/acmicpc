//https://www.acmicpc.net/problem/2443
#include <iostream>
#include <string>
using namespace std;

int main(int n) {
	cin >> n;

	int length = -1;
	for (int i = 0; i < n; i++) {
		length += 2;
	}

	for (int line = 0; line < n; line++) {
		for (int i = 0;i < line; i++)
			cout << " ";
		for (int i = length; i > 0; i--)
			cout << "*";
		length-=2;
		if (line != n-1) cout << "\n";
	}

	return 0;
}