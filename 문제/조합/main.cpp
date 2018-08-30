//https://www.acmicpc.net/problem/2407
#include <iostream>
#include <string>
#include <string.h>
#include <deque>
#include <vector>
using namespace std;

deque<int> cache[101][101];

deque<int> sumDequeNumber(deque<int> a, deque<int> b) {
	deque<int> sum = deque<int>(30);
	for (int i = sum.size() - 1; i >= 0; i--) {

	}
	int sumIndex = sum.size() - 1;
	for (int i = b.size() - 1; i >= 0; i--) {
		if (sum[sumIndex] + b[i] > 9) {
			sum[sumIndex] = sum[sumIndex] + b[i] - 10;
			int upIndex = sumIndex - 1;
			while (sum[upIndex] >= 9) {
				sum[upIndex] = 0;
				sum[--upIndex]++;
			}
		} else {
			sum[sumIndex] += b[i];
		}
		sumIndex--;
	}

	return sum;
}

deque<int> binoMemo(int n, int r) {
	if (r == 0 || n == r) {
		deque<int> res;
		res.push_back(1);
		return res;
	}
	if (cache[n][r].back() != -1)
		return  cache[n][r];

	return cache[n][r] = sumDequeNumber(binoMemo(n - 1, r), binoMemo(n - 1, r - 1));
}

int main() {
	for (size_t i = 0; i < 101; i++){
		for (size_t j = 0; j < 101; j++) {
			cache[i][j].push_back(-1);
		}
	}

	int n, k;
	cin >> n >> k;

	auto result = binoMemo(n, k);
	for (int i : result)
		cout << i;

	return 0;
}