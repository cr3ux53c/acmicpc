#include <iostream>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	queue<int> c;
	queue<int> k;

	for (int i = 0; i < n; i++) {
		int inputC, inputK;
		cin >> inputC >> inputK;
		c.push(inputC);
		k.push(inputK);
	}

	int result = 0;
	
	for (int i = 0; i < n; i++) {
		result += c.front()*k.front();
		c.pop(); k.pop();
	}
	cout << result;

	return 0;
}