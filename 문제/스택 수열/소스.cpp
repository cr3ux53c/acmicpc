//https://www.acmicpc.net/problem/1874

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int length;
	stack<int> st;
	vector<char> output;

	int index = 0;
	st.push(index++);
	cin >> length;

	for (int i = 0; i < length; i++) {
		int input;
		cin >> input; // 1 <= X <= length

		if (st.top() == input) {
			st.pop();
			output.push_back('-');
		} else if (st.top() < input) {
			if (index > input) {
				cout << "NO";
				return 0;
			}
			while (st.top() < input) {
				st.push(index++);
				output.push_back('+');
			}
			st.pop();
			output.push_back('-');
		} else {
			while (st.top() >= input) {
				st.pop();
				output.push_back('-');
			}
		}
	}

	//output
	for (int i : output) cout << i << '\n';

	return 0;
}