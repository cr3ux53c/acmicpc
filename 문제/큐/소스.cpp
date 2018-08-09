#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MyQueue {
	int *queue;
	int fp;
	int bp;
public:
	MyQueue(int size) {
		queue = new int[size];
		fp = 0; bp = -1;
	}
	~MyQueue() {
		delete queue;
	}
	void push(int x) {
		queue[++bp] = x;
	}
	int pop() {
		return (fp > bp) ? -1 : queue[fp++];
	}
	int size() {
		return bp-fp+1;
	}
	bool empty() {
		return (bp - fp == -1) ? true : false;
	}
	int front() {
		return (bp - fp == -1) ? -1 : queue[fp];
	}
	int back() {
		return (bp - fp == -1) ? -1 : queue[bp];
	}
};

int main() {
	int inputCases;
	cin >> inputCases;
	cin.ignore();
	string inputCmd;

	MyQueue myQueue(inputCases);
	vector<int> output;

	for (int i = 0; i < inputCases;i++) {
		getline(cin, inputCmd);
		
		if (inputCmd.compare(0, 4, "push") == 0) {
			myQueue.push(atoi(inputCmd.c_str() + 5));
		}else if (inputCmd.compare(0, 3, "pop") == 0) {
			output.push_back(myQueue.pop());
		} else if (inputCmd.compare(0, 5, "front") == 0) {
			output.push_back(myQueue.front());
		} else if (inputCmd.compare(0, 4, "back") == 0) {
			output.push_back(myQueue.back());
		} else if (inputCmd.compare(0, 4, "size") == 0) {
			output.push_back(myQueue.size());
		} else { // empty
			output.push_back(myQueue.empty());
		}
	}
	//output
	for (int i : output) cout << i << "\n";

	return 0;
}