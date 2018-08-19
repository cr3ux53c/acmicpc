#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

vector<string> MyStrTok(string src, string delimeter) {
	stringstream ss(src);
	vector<string> result;
	string token;

	while (getline(ss, token)) {
		size_t prevPos = 0, pos;
		while ((pos = token.find_first_of(delimeter, prevPos)) != string::npos) {
			if (pos > prevPos)
				result.push_back(token.substr(prevPos, pos - prevPos));
			prevPos = pos + 1;
		}
		if (prevPos < token.length())
			result.push_back(token.substr(prevPos, string::npos));
	}
	return result;
}

int main() {
	int t;
	cin >> t;
	vector<string> result;

	//testCases
	for (int i = 0; i < t; i++) {
		bool isError = false;
		deque<int> d;
		//input
		string cmd;
		cin >> cmd;
		int n;
		cin >> n;
		string arr;
		cin >> arr;
		
		//input array
		vector<string> res = MyStrTok(arr, "[,]");
		for (string s : res) {
			d.push_back(atoi(s.c_str()));
		}

		//run cmds
		bool isReverse = false;
		for (char ch : cmd) { 
			if (ch == 'R') {
				isReverse = !isReverse;
				if (isReverse)
					sort(d.rbegin(), d.rend());
				else
					sort(d.begin(), d.end());
			} else { //D
				if (!d.empty())
					d.pop_front();
				else {
					isError = true;
				}
			}
		}

		//output
		if (isError) {
			cout << "error\n";
		} else {
			cout << '[';
			for (int i = 0; i < d.size(); i++) {
				cout << d[i];
				(i == d.size() - 1) ? cout << ']' : cout << ',';
			}
		}
	}
	return 0;
}