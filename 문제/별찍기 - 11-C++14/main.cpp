//https://www.acmicpc.net/problem/2448
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void printTriangle(int bottomLength, bool isNewLine = false) {
	int length = 1;
	for (int line = 0; line < 3; line++) {
		for (int i = 0; i < floor(bottomLength / 2+0.5) - line; i++)
			cout << " ";
		for (int i = 0; i < length; i++)
			if (line == 1 && i == 1)
				cout << " ";
			else
				cout << "*";
		length += 2;
		if (line != 3 - 1) cout << "\n";
	}
	if (isNewLine)
		cout << '\n';
}

int main(int n) {
	n = 24;
	//cin >> n; //N은 항상 3*2^k 수이다. (3, 6, 12, 24, 48, ...) (k<=10)
	int bottomLength = n * 2 - 1;
	int triangleNumber = (int)pow(3, n/3);
	printTriangle(bottomLength, true);
	printTriangle(bottomLength-5);
	printTriangle(bottomLength+6);
	return 0;
}