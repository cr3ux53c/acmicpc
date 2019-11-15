//https://www.acmicpc.net/problem/1330
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int a, int b) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;

	if (a > b) {
		cout << '>';
	} else if (a < b) {
		cout << '<';
	} else
		cout << "==";
	return 0;
}