//https://www.acmicpc.net/problem/8958
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	cin >> argc;

	for (int i = 0; i < argc; i++) {
		int score = 0;
		string input;
		cin >> input;

		int s = 0;
		for (char i : input) {
			if (i == 'O')
				score += ++s;
			else
				s = 0;
		}
		cout << score << "\n";
	}
	return 0;
}