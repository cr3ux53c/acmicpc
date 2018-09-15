//https://www.acmicpc.net/problem/2750
#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(int argc, char *argv[]) {
	cin >> argc;
	list<int> li;
	for (int i = 0; i < argc; i++) {
		int input; cin >> input;
		li.push_back(input);
	}

	li.sort();
	for (auto i : li)
		cout << i << " ";
	return 0;
}