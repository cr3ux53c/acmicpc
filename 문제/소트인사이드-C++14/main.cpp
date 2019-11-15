//https://www.acmicpc.net/problem/1427
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	string n;
	cin >> n;
	sort(n.rbegin(), n.rend());
	cout << n;
	return 0;
}