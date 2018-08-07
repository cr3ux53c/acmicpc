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
#include <vector>
using namespace std;

enum {NO, YES};

int main() {
	int inputSize = 0;
	cin >> inputSize;
	cin.ignore();
	string inputString;
	vector<int> output;

	for (int i = 0; i < inputSize; i++) {
		getline(cin, inputString);
		stack<bool> ps;

		for (int i = 0; i < inputString.size(); i++) {
			if (inputString.c_str()[i] == '(') {
				ps.push(0);
			} else {
				if (ps.empty()) {
					ps.push(0); // 루프 뒤에서 NO 만들기 위해
					break;
				} else {
					ps.pop();
				}
			}
		}
		output.push_back((ps.empty() == true) ? YES : NO);
	}

	//output
	for (int i : output) cout << ((i == YES) ? "YES\n" : "NO\n");
	
	return 0;
}
