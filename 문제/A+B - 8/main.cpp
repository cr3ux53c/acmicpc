//https://www.acmicpc.net/problem/11022
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int a, int b) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int test_cases;
	cin >> test_cases;

	for (int i = 0; i < test_cases; i++) {
		cin >> a >> b;
		cout << "Case #" << i + 1 << ": " << a << " + " << b << " = " << a + b << endl;
	}

	return 0;
}