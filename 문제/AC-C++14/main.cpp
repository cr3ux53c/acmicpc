//https://www.acmicpc.net/problem/5430
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	vector<string> result;

	//testCases
	for (int i = 0; i < t; i++) {
		bool isError = false;
		deque<string> d;

		//input
		string commands;
		cin >> commands;
		int n;
		cin >> n;
		string arr;
		cin >> arr;

		//input array
		vector<string> res = MyStrTok(arr, "[,]");
		for (string s : res) {
			d.push_back(s);
		}

		//run commands
		int countOfD = 0;
		int beginIndex = 0;
		int endIndex = d.size();
		bool isReverse = false;
		for (char ch : commands) {
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
				} else {
					isError = true;
					break;
				}
			}
		}

		if (countOfD > d.size()) isError = true;

		//output to buffer
		if (isError) {
			result.push_back("error");
		} else {
			stringstream ss;
			ss << '[';
			int begin = isReverse ? endIndex - 1 : beginIndex;
			int end = isReverse ? beginIndex - 1 : endIndex;
			int flag = isReverse ? -1 : 1; // R에 따라 달라지는 인덱스 증감치
			if (begin == end) { //덱이 비어있을 경우
				ss << ']';
			} else { // 지정된 범위의 덱 순회
				for (int i = begin; i != end; i += flag) {
					ss << d[i];
					(i == end + (isReverse ? 1 : -1)) ? ss << ']' : ss << ',';
				}
			}
			result.push_back(ss.str());
		}
	}

	//output
	for (auto s : result) cout << s << '\n';
	
	return 0;
}