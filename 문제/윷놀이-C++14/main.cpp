//https://www.acmicpc.net/problem/2490
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int RESULT[] = { 'E', 'A', 'B', 'C', 'D' };

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 3; i++) { //testCases
		int count = 0;

		for (int j = 0; j < 4; j++) {
			bool input; cin >> input;
			if (input == 0) count++;
		}
		
		cout << (char)RESULT[count] << '\n';
	}

	return 0;
}