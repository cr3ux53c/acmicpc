//https://www.acmicpc.net/problem/2577
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]) {
	int sum = 1;
	cin >> argc;
	sum *= argc;
	cin >> argc;
	sum *= argc;
	cin >> argc;
	sum *= argc;

	int arr[10] = { 0 };
	while (sum > 0) {
		arr[(sum % (int)pow(10, 1))]++;
		sum /= 10;
	}

	for (auto i : arr)
		cout << i << "\n";
	return 0;
}