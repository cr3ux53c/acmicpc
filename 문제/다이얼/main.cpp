//https://www.acmicpc.net/problem/5622
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	string s; cin >> s;

	int result = 0;
	for (auto i : s) {
		result += ((i - 65) / 3) + 3;
		if (i == 'S' || i == 'V' || i == 'Y' || i == 'Z') result--;
	}
	cout << result;
	return 0;
}