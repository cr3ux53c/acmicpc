//https://www.acmicpc.net/problem/15596
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long sum(std::vector<int>& a) {
	long long ans = 0;

	for (auto it = a.begin(); it != a.end(); it++) {
		ans += *it;
	}

	return ans;
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	vector<int> aa = vector<int>(10, 10);

	cout << sum(aa);


	return 0;
}