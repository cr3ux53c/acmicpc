//https://www.acmicpc.net/problem/3052
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<int> remains;

	for (int i = 0; i < 10; i++) {
		cin >> argc;
		remains.push_back(argc % 42);
	}

	sort(remains.begin(), remains.end());
	remains.erase(unique(remains.begin(), remains.end()), remains.end());
	cout << remains.size();
	return 0;
}