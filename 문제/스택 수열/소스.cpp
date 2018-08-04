//https://www.acmicpc.net/problem/1874

#include <iostream>
#include <stack>
using namespace std;

stack<int> st;

int main(){
	int length;

	int index = 0;
	st.push(index++);
	cin >> length;

	for (int i = 0; i < length; i++) {
		int input;
		cin >> input; // 1 <= X <= length

		if (st.top() == input) {
			st.pop();
			cout << '-' << endl;
		} else if (st.top() < input) {
			if (index > input) {
				cout << "NO";
				return 0;
			}
			while (st.top() < input) {
				st.push(index++);
				cout << '+' << endl;
			}
			st.pop();
			cout << '-' << endl;
		} else {
			while (st.top() >= input) {
				st.pop();
				cout << '-' << endl;
			}
		}
	}

	return 0;
}