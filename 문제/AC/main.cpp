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
		int countOfD = 0;
		int beginIndex = 0;
		int endIndex = d.size()-1;
		bool isReverse = false;
		for (char ch : cmd) { 
			if (ch == 'R') {
				isReverse = !isReverse;
			} else { // D
				countOfD++;
				if (!d.empty()) {
					if (isReverse) {
						endIndex--;
					} else {
						beginIndex++;
					}
				}
				else {
					isError = true;
					break;
				}
			}
		}

		if (countOfD > d.size()) isError = true;

		//output
		if (isError) {
			result.push_back("error");
		} else {
			string s;
			s.push_back('[');
			
			int begin = isReverse ? endIndex : beginIndex;
			int end = isReverse ? beginIndex : endIndex;
			end += isReverse ? -1 : 1;
			int flag = isReverse ? -1:1;

			for (int i = begin; i != end; i+=flag) {
				s.push_back(d[i][0]);
				(i == end + (isReverse ? 1 : -1)) ? s.push_back(']') : s.push_back(',');
			}
			result.push_back(s);
		}
	}

	for (string s : result)
		cout << s << '\n';

	return 0;
}