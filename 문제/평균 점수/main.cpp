#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<int> v;

	for (int i = 0; i < 5; i++) {
		int input;
		cin >> input;
		if (input < 40)
			input = 40;
		v.push_back(input);
	}

	int sum = 0;
	for (auto i : v) {
		sum += i;
	}

	cout << sum / 5;
	return 0;
}