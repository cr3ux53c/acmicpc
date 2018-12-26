//https://www.acmicpc.net/problem/10989
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
	int n;
	vector<int> list = vector<int>(10000, 0);

	cin >> n;
	for (short i = 0; i < n; i++) {
		short input; cin >> input;
		list[input - 1]++;
	}

	//output
	for (int i = 0; i < list.size(); i++) {
		for (int j = 0; j < list[i]; j++) {
			cout << i + 1 << '\n';
		}
	}

	return 0;
}