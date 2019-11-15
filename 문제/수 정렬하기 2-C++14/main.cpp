//https://www.acmicpc.net/problem/2751
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) { 
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	vector<int> list;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		list.push_back(input);
	}

	sort(list.begin(), list.end());

	for (auto i : list)
		cout << i << '\n';

	return 0;
}