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
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	vector<string> result;

	//testCases
	for (int i = 0; i < t; i++) {
		bool isError = false;
		deque<string> d;
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
			d.push_back(s);
		}

		//run cmds
		int beginIndex = 0;
		int endIndex = d.size();
		bool isReverse = false;
		for (char ch : cmd) { 
			if (ch == 'R') {
				isReverse = !isReverse;
				/*if (isReverse)
					sort(d.rbegin(), d.rend());
				else
					sort(d.begin(), d.end());*/
			} else { // D
				if (!d.empty())
					if (isReverse) {
						endIndex--;
					} else {
						beginIndex++;
					}
				else {
					isError = true;
					break;
				}
			}
		}

		//output
		if (isError) {
			//cout << "error\n";
			result.push_back("error");
		} else {
			string s;
			s.push_back('[');
			//cout << '[';
			for (int i = 0; i < d.size(); i++) {
				//cout << d[i];
				//(i == d.size() - 1) ? cout << ']' : cout << ',';
				s.push_back(d[i][0]);
				(i == d.size() - 1) ? s.push_back(']') : s.push_back(',');
			}
			result.push_back(s);
		}
	}

	for (string s : result)
		cout << s << '\n';

	return 0;
}