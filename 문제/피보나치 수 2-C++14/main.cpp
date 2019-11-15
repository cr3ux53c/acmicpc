//https://www.acmicpc.net/problem/2748
#include <iostream>
#include <string>
using namespace std;

long long getFibonacci(int n) {
	long long a = 0, b = 1;
	long long tmp;

	for (int i = 0; i < n - 1; i++) {
		tmp = b;
		b = a + b;
		a = tmp;
	}
	return b;
}

int main() {
	int n;
	cin >> n;
	cout << getFibonacci(n);

	return 0;
}