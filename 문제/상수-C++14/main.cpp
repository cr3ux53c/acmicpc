//https://www.acmicpc.net/problem/2908
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]) {
	int input[2]; cin >> input[0] >> input[1];
	int result[2] = { 0 };

	for (int i = 0; i < 2; i++) {
		int k = 2;
		for (int l = 0;l<3;l++){
			result[i] += (input[i] % 10) * pow(10, k--);
			input[i] /= 10;
		}
	}
	
	result[0] > result[1] ? cout << result[0] : cout << result[1];
	return 0;
}