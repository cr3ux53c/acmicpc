//https://www.acmicpc.net/problem/11051
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int cache[1001][1001];

int binoMemo(int n, int r) {
	if (r == 0 || n == r) return 1;
	if (cache[n][r] != -1)
		return  cache[n][r];
	return cache[n][r] = (binoMemo(n - 1, r - 1) + binoMemo(n - 1, r)) % 10007;
}

int main() {
	memset(cache, -1, 1001*1001*sizeof(int));

	int n, k;
	cin >> n >> k;

	int result = binoMemo(n, k);
	cout << result << '\n';

	return 0;
}