//https://www.acmicpc.net/problem/2753
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> argc;

	if (argc % 4 == 0 && (argc % 100 != 0 || argc % 400 == 0)) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}