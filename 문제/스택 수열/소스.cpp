//https://www.acmicpc.net/problem/1874

#include <iostream>
using namespace std;

//stack<int> st;
int st[100000];
int index, sp;

int main(){
	int length;

	//st.push(index++);
	st[sp] = index++; sp++;
	cin >> length;

	for (int i = 0; i < length; i++) {
		int input;
		cin >> input; // 1 <= X <= length

		if (st[sp-1] == input) {
			sp--;
			cout << '-' << endl;
		} else if (st[sp - 1] < input) {
			if (index > input) {
				cout << "NO";
				return 0;
			}
			while (st[sp - 1] < input) {
				st[sp] = index++; sp++;
				cout << '+' << endl;
			}
			sp--;
			cout << '-' << endl;
		} else {
			while (st[sp - 1] >= input) {
				sp--;
				cout << '-' << endl;
			}
		}
	}

	return 0;
}