//https://www.acmicpc.net/problem/10809
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;

	vector<int> arr(26, -1);
	for (int i = s.size()-1; i >= 0; i--)
		arr[s[i] - 97] = i;
	for (auto i : arr)
		cout << i << " ";
	return 0;
}