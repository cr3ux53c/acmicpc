//https://www.acmicpc.net/problem/10828

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MyStack {
	int length;
	int* stack;
	int sp;
public:
	MyStack(int size) {
		this->length = size;
		stack = new int[size];
		sp = -1;
	}
	~MyStack() {
		delete(stack);
	}
	int push(int x) { //1<=x<=100000
		if (sp == length - 1) return -1;
		stack[++sp] = x;
		return x;
	}
	int pop() {
		if (sp == -1) return -1;
		return stack[sp--];
	}
	int size() {
		return sp + 1;
	}
	bool empty() {
		if (sp == -1) return true; else return false;
	}
	int top() {
		if (sp == -1) return -1;
		return stack[sp];
	}
};

int main() {
	int inputSize = 0;
	cin >> inputSize;
	cin.ignore();
	string inputCommand;
	MyStack mystack(inputSize);

	//출력 버퍼
	vector<int> output;

	for (int i = 0; i < inputSize; i++) {
		getline(cin, inputCommand);
		if (inputCommand.compare(0, 4, "push") == 0) {
			mystack.push(atoi(inputCommand.c_str() + 5));
		}
		if (inputCommand.compare(0, 3, "top") == 0) {
			output.push_back(mystack.top());
		}
		if (inputCommand.compare(0, 4, "size") == 0) {
			output.push_back(mystack.size());
		}
		if (inputCommand.compare(0, 5, "empty") == 0) {
			output.push_back(mystack.empty());
		}
		if (inputCommand.compare(0, 3, "pop") == 0) {
			output.push_back(mystack.pop());
		}
	}

	//출력
	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << endl;
	}

	return 0;
}