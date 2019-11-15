#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int d(int digitNumber, int n) {
	int sum = n;
	sum += n % 10;
	for (int i = 1; i < digitNumber; i++)
		sum += (n / (int)pow(10, i)) % 10;
	return sum;
}

int getDigitNumber(int n) {
	int count = 1;
	double i = 10;
	while (i <= n) {
		i *= 10;
		count++;
	}
	return count;
}

int main() {
	vector<bool> selfNumber(10036);
	for (int i = 1; i <= 10000;i++)
		selfNumber[d(getDigitNumber(i), i)] = true;
	
	for (int i =1;i<10001;i++)
		if (!selfNumber[i]) cout << i << '\n';
	return 0;
}