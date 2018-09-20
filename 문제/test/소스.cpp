#pragma warning (disable:4996)
#include <iostream>
#include <string>
using namespace std;

int main() {

	string s; getline(cin, s);
	for (auto i : s)
		cout << (int)i << ", ";
	return 0;
}