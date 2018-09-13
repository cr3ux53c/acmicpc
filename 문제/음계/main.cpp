//https://www.acmicpc.net/problem/2920
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main(int argc, char *argv[]) {
	char arr[9] = { 0 };
	for (int i = 0; i < 8; i++)
		cin >> arr[i];

	if (strcmp(arr, "12345678") == 0)
		cout << "ascending";
	else if (strcmp(arr, "87654321") == 0)
		cout << "descending";
	else
		cout << "mixed";
	return 0;
}