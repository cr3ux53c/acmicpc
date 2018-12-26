//https://www.acmicpc.net/problem/5397
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

int main(int testCases, char* argv[]) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> testCases;

	for (int i = 0; i < testCases; i++) {
		string input; cin >> input;
		string output = "";
		int pos = 0;
		
		for (int i = 0; i < input.size(); i++) {
			switch (input[i]) {
				case '<':
					if (pos > 0) pos--;
					break;
				case '>':
					if (pos < output.size()) pos++;
					break;
				case '-':
					if (pos > 0) {
						output.erase(pos-1, 1);
						pos--;
					}
					break;
				default:
					output.insert(pos++, input.substr(i, 1));
					break;
			}
		}
		cout << output << '\n';
	}

	return 0;
}