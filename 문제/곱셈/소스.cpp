//https://www.acmicpc.net/problem/2588
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int a, int b) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;
	vector<int> result = vector<int>();
	result.push_back(a * (b % 10));
	result.push_back(a * (b % 100 / 10));
	result.push_back(a * (b / 100 % 10));


	for (int i : result) {
		cout << i << endl;
	}
	cout << a * b;
	return 0;
}