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

void Check(stack<int> *stak, int OPEN) {
	int sum = 0;
	while (!stak->empty()) { // 차있을 때 동안
		if (stak->top() == OPEN) {
			stak->pop();
			if (sum == 0)
				stak->push(OPEN == SMALL_OPEN ? 2 : 3);
			else
				stak->push(sum * (OPEN == SMALL_OPEN ? 2 : 3));
			break;
		}
		else if (stak->top() == (OPEN == SMALL_OPEN ? BIG_OPEN : SMALL_OPEN)) {
			throw - 1;
		}
		else {
			sum += stak->top();
			stak->pop();
		}
	}
	if (stak->empty()) throw - 1;
}

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
				Check(&stak, SMALL_OPEN);
				break;
			case ']':
				Check(&stak, BIG_OPEN);
				break;
			default:
				throw -1;
			}
		} catch (int e) { //ERROR
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