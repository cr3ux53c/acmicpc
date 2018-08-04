//https://www.acmicpc.net/problem/9012
/*
13
)(()
())(
(())())(
(())())
())
(((((()((()))))))
(((()((()))))))
((
)()
))
)))
))))
)))))
*/

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
		stack<bool> ps;

		for (int i = 0; i < inputCommand.size(); i++) {
			if (inputCommand.c_str()[i] == '(') {
				ps.push(0);
			} else {
				if (ps.empty()) {
					ps.push(0);
					break;
				} else {
					ps.pop();
				}
			}
		}
		if (ps.empty()) {
			output[++outputSp] = YES;
		}else {
			output[++outputSp] = NO;
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
