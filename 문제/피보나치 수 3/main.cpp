//https://www.acmicpc.net/problem/2748
//https://www.acmicpc.net/blog/view/28
#include <iostream>
#include <string>
using namespace std;

int getFibonacci(unsigned long long n) {
	int a = 0, b = 1, tmp;
	for (unsigned long long i = 0; i < n - 1; i++) {
		tmp = b;
		b = (a + b < 1000000) ? a + b : (a + b) % 1000000;
		a = tmp;
	}
	return b;
}

int main() {
	unsigned long long n;
	cin >> n;
	int periodLength = 1500000;
	cout << getFibonacci(n%periodLength);
	return 0;
}