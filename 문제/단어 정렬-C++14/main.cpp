//https://www.acmicpc.net/problem/1181
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int n, char* argv[]) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	vector<vector<string>> lists = vector<vector<string>>(20000, vector<string>());

	for (int i = 0; i < n; i++) {
		string input; cin >> input;
		lists[input.size() - 1].push_back(input);
	}

	//output
	//왜 sort(list.begin(), list.end());는 반영이 안되고 변수를 새로 만들어야만 하나?
	for (auto list : lists) {
		vector<string> l = list;
		sort(l.begin(), l.end());

		l.erase(unique(l.begin(), l.end()), l.end());

		for (auto i : l) cout << i << '\n';
	}

	return 0;
}