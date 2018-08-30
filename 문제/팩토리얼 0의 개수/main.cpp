//https://www.acmicpc.net/problem/1676
#include <iostream>
#include <string>
using namespace std;

unsigned long long factorial(int n){
	unsigned long long result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

int main() {
	int n;
	cin >> n;

	for (size_t i = 0; i < 25; i++) {
		cout << factorial(i+1) << '\n';
	}
	
	return 0;
}