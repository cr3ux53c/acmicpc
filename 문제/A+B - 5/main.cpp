//https://www.acmicpc.net/problem/10952
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int a, int b) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		cout << a + b << endl;
	}

	return 0;
}