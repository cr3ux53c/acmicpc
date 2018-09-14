//https://www.acmicpc.net/problem/2455
#include <iostream>
using namespace std;

int main() {

	int result = 0, number = 0;
	for (int i = 0; i < 4; i++) {
		int in, out;
		cin >> out >> in;
		number -= out;
		number += in;
		if (result < number) result = number;
	}
	cout << result;
	return 0;
}