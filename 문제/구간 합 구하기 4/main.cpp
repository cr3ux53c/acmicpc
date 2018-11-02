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
	vector<int> prefixSum(n);
	cin >> prefixSum[0];
	for (int i = 1; i < n; i++) {
		int input; cin >> input;
		prefixSum[i] = prefixSum[i - 1] + input;
	}

	//calc
	for (int i = 0; i < m; i++) {
		int start, end; cin >> start >> end;
		cout << prefixSum[end - 1] - (start - 2 < 0 ? 0 : prefixSum[start - 2]) << '\n';
	}

	return 0;
}