//https://www.acmicpc.net/problem/10866
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int deque[10009]; //10008°³ runtime error why?

class MyDeque {
	int fp;
	int bp;
public:
	MyDeque(int size) {fp = size; bp = size-1;}
	void pushFront(int x) {deque[--fp] = x;}
	void pushBack(int x) {deque[++bp] = x;}
	int popFront() {return (fp > bp) ? -1 : deque[fp++];}
	int popBack() {return (fp > bp) ? -1 : deque[bp--];}
	int size() {return bp - fp + 1;}
	bool empty() {	return (bp - fp == -1) ? true : false;}
	int front() {return (bp - fp == -1) ? -1 : deque[fp];}
	int back() {return (bp - fp == -1) ? -1 : deque[bp];}
};

const string COMMANDS[11] = {
	"push_front",
	"push_back",
	"pop_front",
	"pop_back",
	"size",
	"empty",
	"front",
	"back",
};

int main() {
	//input
	int inputCases;
	cin >> inputCases;
	cin.ignore();
	string inputCmd;
	MyDeque myDeque(inputCases);
	vector<int> output;

	for (int i = 0; i < inputCases; i++) {
		getline(cin, inputCmd);
		if (inputCmd.compare(0, COMMANDS[0].size(), COMMANDS[0]) == 0) {
			myDeque.pushFront(atoi(inputCmd.c_str() + COMMANDS[0].size()));
		} else if (inputCmd.compare(0, COMMANDS[1].size(), COMMANDS[1]) == 0) {
			myDeque.pushBack(atoi(inputCmd.c_str() + COMMANDS[0].size()));
		} else if (inputCmd.compare(0, COMMANDS[2].size(), COMMANDS[2]) == 0) {
			output.push_back(myDeque.popFront());
		} else if (inputCmd.compare(0, COMMANDS[3].size(), COMMANDS[3]) == 0) {
			output.push_back(myDeque.popBack());
		} else if (inputCmd.compare(0, COMMANDS[4].size(), COMMANDS[4]) == 0) {
			output.push_back(myDeque.size());
		} else if (inputCmd.compare(0, COMMANDS[5].size(), COMMANDS[5]) == 0) {
			output.push_back(myDeque.empty());
		} else if (inputCmd.compare(0, COMMANDS[6].size(), COMMANDS[6]) == 0) {
			output.push_back(myDeque.front());
		} else{
			output.push_back(myDeque.back());
		}
	}
	//output
	for (int i : output) cout << i << '\n';
	return 0;
}