//https://www.acmicpc.net/problem/11050
#include <iostream>
#include <string>
using namespace std;

int factorial(int n) {
	int resultN = 1;
	for (size_t i = 2; i <= n; i++)
		resultN *= i;
	return resultN;
}

int binomialCoefficient(int n, int k) {
	return factorial(n) / (factorial(k) * factorial(n-k));
}

int main() {
	int n, k;
	cin >> n >> k;

	int result = binomialCoefficient(n, k);
	cout << result;

	return 0;
}