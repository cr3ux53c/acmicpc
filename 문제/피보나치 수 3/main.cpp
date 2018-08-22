//https://www.acmicpc.net/problem/2748
#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int getDigitNumber(unsigned long long n) {
	int count = 1;
	while (n / 10 >= 1) {
		count++;
		n /= 10;
	}
 	return count;
}

deque<int> sumDeques(deque<int> a, deque<int> b) {
	deque<int> sum = b;
	int sumIndex = sum.size() - 1;
	int aIndex = a.size() - 1;

	for (int i = aIndex; i >= 0;i--) {
		if (sum[sumIndex] + a[i] >= 10) {
			sum[sumIndex] += a[i] - 10;
			if (sumIndex == 0)
				sum.push_front(1);
			else
				sum[--sumIndex] += 1;
		} else {
			sum[sumIndex--] += a[i];
		}
	}
	return sum;
}

deque<int> getFibonacci(unsigned long long n) {
	int digitNumber = getDigitNumber(n);
	deque<int> a; a.push_back(0);
	deque<int> b; b.push_back(1);
	deque<int> tmp;

	for (unsigned long long i = 0; i < n - 1; i++) {
		tmp = b;
		b = sumDeques(a, b);
		a = tmp;
		//if (b.size() > 2) break;

	}

	return b;
}

int main() {
	unsigned long long n;
	//cin >> n;
	//cout << getFibonacci(1000);
	auto result = getFibonacci(1000);
	for (auto i : result) cout << i;
	getFibonacci(1000000000000000000);

	return 0;
}