//https://www.acmicpc.net/problem/10951
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int a, int b) {
	//ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int input;
	while (input = getchar()) {
		if (input == EOF)
			break;

		a = input - 48;
		getchar();
		b = getchar() - 48;
		getchar();
		cout << a + b << endl;
	}

	return 0;
}