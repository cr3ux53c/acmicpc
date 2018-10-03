//https://www.acmicpc.net/problem/1991
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int n;
vector<pair<char, pair<char, char>>> matrix;

//void preorderTraversal(int index) {
//	auto edge = matrix[index];
//	for (auto it = edge.begin(); it != edge.end(); it++) {
//		if (it == edge.begin()) {
//			cout << *it;
//		} else if (*it != '.') {
//			int nextIndex;
//			for (int i = 0; i < n; i++) {
//				if (*matrix[i].begin() == *it){
//					nextIndex = i;
//					break;
//				}
//			}
//			preorderTraversal(nextIndex);
//		} else
//			continue;
//	}
//}
//
//void inorderTraversal(int index) {
//	auto edge = matrix[index];
//	for (auto it = edge.begin(); it != edge.end(); it++) {
//		if (it == edge.end()) {
//			cout << *it;
//		} else if (*it != '.') {
//			int nextIndex;
//			for (int i = 0; i < n; i++) {
//				if (*matrix[i].begin() == *it) {
//					nextIndex = i;
//					break;
//				}
//			}
//			inorderTraversal(nextIndex);
//		} else // '.'
//			continue;
//	}
//}

int main(int argc, char* argv[]) { 
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	//input
	pair<char, char> a = pair<char, char>();
	cin >> n;
	matrix = vector<pair<char, pair<char, char>>>(n, pair<char, pair<char, char>>());
	for (int i = 0; i < n; i++) {
		pair<char, pair<char, char>> input;
		char ch[3];
		for (int j = 0; j < 3; j++)
			cin >> ch[j];
		input.first = ch[0];
		input.second = pair<char, char>(ch[1], ch[2]);
		matrix[i] = input;
	}

	//calc
	//preorderTraversal(0);
	cout << "\n";
	
	return 0;
}