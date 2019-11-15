//https://www.acmicpc.net/problem/11401
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

//vector<vector<int>> cache;
int cache[100][100];

int binoMemo(int n, int r) {
	if (r == 0 || n == r) return 1;
	if (cache[n][r] != -1) {
		cout << n << ", " << r << '\n';
		return  cache[n][r];
	}
	return cache[n][r] = (binoMemo(n - 1, r - 1) + binoMemo(n - 1, r)) % 1000000007;
}

int main() {
	int n, k;
	cin >> n >> k;
	memset(cache, -1, 1001 * 1001 * sizeof(int));
	int cache[100][100];
	//vector<int> a(4000000);
	//cache = vector<vector<int>>(n + 1, vector<int>(k + 1));

	int result = binoMemo(n, k);
	cout << result << '\n';

	return 0;
}