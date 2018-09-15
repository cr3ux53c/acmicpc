//https://www.acmicpc.net/problem/2675
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {
	cin >> argc;

	//testCase
	for (int i = 0; i < argc; i++) {
		int r; cin >> r;
		string s; cin >> s;
		stringstream ss;
		for (auto i : s)
			for (int j=0;j<r;j++)
				ss.put(i);
		cout << ss.str() << "\n";
	}
	return 0;
}