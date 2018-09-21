#pragma warning (disable:4996)
#include <iostream>
#include <string>
using namespace std;

void pick(int n, int pickCount) {
	//baseCase
	if (pickCount < 0) {
		cout << endl;
		return;
	}
	//calc
	for (int i = 0; i < pickCount; i++) {
		cout << i << ", ";
		pick(n, pickCount - 1);
	}
}

int main() {
	pick(3, 2);
	return 0;
}