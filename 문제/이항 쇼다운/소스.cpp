//https://www.acmicpc.net/problem/11051
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int cache[1001][1001];

int binoMemo(int n, int r) {
	if (r == 0 || n == r) return 1;
	if (cache[n][r] != -1)
		return  cache[n][r];
	return cache[n][r] = (binoMemo(n - 1, r - 1) + binoMemo(n - 1, r));
}

unsigned long long factorial(unsigned long long n) {
	unsigned long long resultN = 1;
	for (size_t i = 2; i <= n; i++)
		resultN *= i;
	return resultN;
}

unsigned long long bino(int n, int r) {
	return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
	while (1) {
		int n, r;
		cin >> n >> r;
		if (n == r && r == 0) break;

		unsigned long long result = bino(n, r);
		cout << result << '\n';
	}

	return 0;
}