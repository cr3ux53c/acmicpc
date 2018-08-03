//https://www.acmicpc.net/problem/2504

#include <iostream>
#include <string>
#include <stack>
using namespace std;



int main() {
	string inputCommand;
	getline(cin, inputCommand);

	stack<char> st;
	stack<int> calc;
	int result = 0;

	for (int i = 0; i < inputCommand.size(); i++) {
		switch (inputCommand.c_str()[i]) {
		case '(':
			st.push('(');
			break;
		case ')':
			if (st.top() == '(') {
				st.pop();
				calc.push(2);
			}
			else {
				return 0;
			}
			break;
		}

		

	}


	return 0;
}