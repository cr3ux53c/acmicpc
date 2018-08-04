//https://www.acmicpc.net/problem/2504
/*
(()()[]
([)]
(()
())
))
)
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

enum {SMALL_OPEN = -1, BIG_OPEN = -2};

int main() {
	string inputCommand;
	getline(cin, inputCommand);
	
	stack<int> stak;

	if (inputCommand.size() < 2) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < inputCommand.size(); i++) {
		try{
			switch (inputCommand[i]) {
			case '(':
				stak.push(SMALL_OPEN);
				break;
			case '[':
				stak.push(BIG_OPEN);
				break;
			case ')':
				if (stak.empty()) throw - 1;
				if (stak.top() == SMALL_OPEN) {
					stak.pop();
					stak.push(2);
				} else { //numbers
					int sum = 0;
					if (stak.empty()) throw - 1;
					while (stak.top() != SMALL_OPEN) {
						if (stak.top() == BIG_OPEN) throw -1;
						sum += stak.top();
						stak.pop();
					}
					stak.pop();
					stak.push(sum * 2);
				}
				break;
			case ']':
				if (stak.empty()) throw - 1;
				if (stak.top() == BIG_OPEN) {
					stak.pop();
					stak.push(3);
				}
				else { //numbers
					int sum = 0;
					if (stak.empty()) throw - 1;
					while (stak.top() != BIG_OPEN) {
						if (stak.top() == SMALL_OPEN) throw -1;
						sum += stak.top();
						stak.pop();
					}
					stak.pop();
					stak.push(sum * 3);
				}
				break;
				break;
			default:
				throw -1;
			}
		} catch (int e) {
			cout << 0;
			return 0;
		}
	}

	int sum = 0;
	while (stak.size()) {
		if (stak.top() < 2) {
			cout << 0;
			return 0;
		}
		sum += stak.top();
		stak.pop();
	}	

	//output
	cout << sum;
	return 0;
}