//https://www.acmicpc.net/problem/11003
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) { 
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	//input
	int N, L; cin >> N >> L;
	deque<int> dq;

	int start, end, result;

	for (int offset = 0;offset<N;offset++) {
		start = max(offset - L + 1, 0);
		end = offset + 1;

		int input; cin >> input;
		dq.push_back(input);
		
		result = INT32_MAX;
		for (auto it = dq.begin(); it != dq.end(); it++)
			result = min(result, *it);

		cout << result << " ";

		if (offset - L + 1 >= 0)
			dq.pop_front();
	}

	return 0;
}