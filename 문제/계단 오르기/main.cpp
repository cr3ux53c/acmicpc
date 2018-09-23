//https://www.acmicpc.net/problem/2579
#pragma warning (disable:4996)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxResult = -1;

int jump(vector<int>& arr, int prevStair, int currentStair) {
	int sum = 0;
	//baseCase
	if (currentStair < 0)
		return 0;

	//calc
	if (prevStair != currentStair + 1) // 두번 연속 계단이 아니면
		return arr[currentStair] + jump(arr, currentStair, currentStair - 1);
	return arr[currentStair] + jump(arr, currentStair, currentStair - 2);


}


int main(int n, char *argv[]) {
	//input
	cin >> n;
	vector<int> arr(n, -1);
	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		arr[i] = input;
	}

	//calc
	cout << jump(arr, n - 1, n - 1);

	return 0;
}