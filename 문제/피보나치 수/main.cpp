//https://www.acmicpc.net/problem/2747
#include <iostream>
#include <string>
using namespace std;

int getFibonacci(int n) {
	int a = 0, b = 1;
	int tmp;
	
	for (int i = 0; i < n-1; i++) {
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