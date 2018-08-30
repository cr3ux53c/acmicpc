//https://www.acmicpc.net/problem/6591
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

unsigned long long factorial(int n, int until = 1) {
	unsigned long long resultN = 1;
	for (int i = n; i > until; i--) {
		resultN *= i;
		//_STL_ASSERT(resultN != ULLONG_MAX, "overflow");
	}
	return resultN;
}

int bino(int n, int r) {
	if (r > n-r) {
		return factorial(n, r) / (factorial(n-r));
	} else {
		return factorial(n, n-r) / (factorial(r));
	}
}

int main() {
	while (1) {
		int n, r;
		cin >> n >> r;
		if (n == 0 && r == 0) break;
		cout << bino(n, r) << '\n';
	}

	return 0;
}