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
	vector<int> prefixSum(n);
	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		vec[i] = input;
	}

	//calc
		//prefix sum
	prefixSum[0] = vec[0];
	for (int i = 1; i < n; i++) {
		prefixSum[i] = prefixSum[i-1] + vec[i];
	}

	//calc
	for (int i = 0; i < m; i++) {
		int start, end; cin >> start >> end;
		int operandEnd;
		if (start - 2 < 0)
			operandEnd = 0;
		else
			operandEnd = prefixSum[start - 2];
		cout << prefixSum[end - 1] - operandEnd << '\n';
	}

	return 0;
}