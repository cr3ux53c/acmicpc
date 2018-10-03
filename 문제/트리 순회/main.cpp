//https://www.acmicpc.net/problem/1991
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int n;
vector<list<char>> matrix;

void preorderTraversal(int index) {
	auto edge = matrix[index];
	for (auto it = edge.begin(); it != edge.end(); it++) {
		if (it == edge.begin()) {
			cout << *it;
		} else if (*it != '.') {
			int nextIndex;
			for (int i = 0; i < n; i++) {
				if (*matrix[i].begin() == *it){
					nextIndex = i;
					break;
				}
			}
			preorderTraversal(nextIndex);
		} else
			continue;
	}
}

void inorderTraversal(int index) {
	auto edge = matrix[index];
	for (auto it = edge.begin(); it != edge.end(); it++) {
		if (it == edge.end()) {
			cout << *it;
		} else if (*it != '.') {
			int nextIndex;
			for (int i = 0; i < n; i++) {
				if (*matrix[i].begin() == *it) {
					nextIndex = i;
					break;
				}
			}
			inorderTraversal(nextIndex);
		} else // '.'
			continue;
	}
}

int main(int argc, char* argv[]) { 
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	//input
	cin >> n;
	matrix = vector<list<char>>(n, list<char>(3));
	for (int i = 0; i < n; i++) {
		list<char> input;
		for (int j = 0; j < 3; j++) {
			char ch; cin >> ch;
			input.push_back(ch);
		}
		matrix[i] = input;
	}

	//calc
	preorderTraversal(0);
	cout << "\n";
	
	return 0;
}