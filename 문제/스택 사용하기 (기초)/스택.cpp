//https://www.acmicpc.net/problem/10828

#include <iostream>
#include <string>
using namespace std;

class MyStack {
	int size;
	int* stack;
	int sp;
public:
	MyStack() {
		MyStack(10000);
	}
	MyStack(int size) {
		this->size = size;
		stack = new int[size];
		sp = -1;
	}
	~MyStack() {
		delete(stack);
	}
	int push(int x) { //1<=x<=100000
		if (sp == size - 1) return -1;
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
	//ют╥б
	int inputSize = 0;
	char inputCmd[7] = { 0 };
	string inputCommand;

	cin >> inputSize;

	MyStack mystack(inputSize);

	for (int i = 0; i < inputSize; i++) {
		cin >> inputCommand;
		inputCommand.compare()
	}

	
}