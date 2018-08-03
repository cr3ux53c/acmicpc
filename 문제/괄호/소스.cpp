//https://www.acmicpc.net/problem/9012

#include <iostream>
#include <string>
#include <stack>
using namespace std;

enum {NO, YES};

int main() {
	int inputSize = 0;
	cin >> inputSize;
	cin.ignore();
	string inputCommand;

	//출력용 배열
	int *output = new int[inputSize];
	int outputSp = -1;

	for (int i = 0; i < inputSize; i++) {
		getline(cin, inputCommand);
		stack<int> ps;

		for (int i = 0; i < inputCommand.size(); i++) {
			switch (inputCommand.c_str()[i]) {
			case '(':
				ps.push(0);
				break;
			case ')':
				if (!ps.empty())
					ps.pop();
				else
					ps.push(0);
			}
		}
		if (!ps.empty()) {
			output[++outputSp] = NO;
		}else {
			output[++outputSp] = YES;
		}
	}

	//출력
	for (int i = 0; i <= outputSp; i++) {
		if (output[i] == YES) {
			cout << "YES" << endl;
		}else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
