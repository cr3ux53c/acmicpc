//https://www.acmicpc.net/problem/1152
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string input(1000001, '\0');

int main(int argc, char *argv[]) {
	getline(cin, input);
	istringstream iss(input);
	string token;
	int count = 0;
	while (getline(iss, token, ' ')) {
		if (token.compare("") == 0) continue;
		count++;
	}
	cout << count;
	return 0;
}