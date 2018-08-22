#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int getDigitNumber(int n) {
	int count = 1;
	while (n / 10 >= 1) {
		count++;
		n /= 10;
	}
	return count;
}

int main() {
	int n;
	cin >> n;
	int count = 0;

	for (int i = 1; i <= n; i++) {
		int digitNumber = getDigitNumber(i);
		vector<int> vec;
		
		if (digitNumber < 3) {
			count++;
			continue;
		}

		for (int j=digitNumber-1;j>=0;j--) {
			vec.push_back((i / (int)pow(10, j)) % 10);
		}
		int d = vec[1] - vec[0];

		bool isRight = true;
		for (int j = 2; j < vec.size();j++) {
			if (vec[j] - vec[j - 1] != d) {
				isRight = false;
				break;
			}
		}
		if (isRight) count++;
	}
	cout << count;

	return 0;
}