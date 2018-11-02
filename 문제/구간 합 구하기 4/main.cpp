//https://www.acmicpc.net/problem/11659
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) { 
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	//input
	int n, m; cin >> n >> m;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		vec[i] = input;
	}

	//calc
	for (int i = 0; i < m; i++) {
		int start, end; cin >> start >> end;
		int sum = 0;

		for (auto it = vec.begin() + start - 1; it != vec.end()-n+end; it++)
			sum += *it;
		cout << sum << '\n';
	}

	return 0;
}