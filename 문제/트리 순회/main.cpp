//https://www.acmicpc.net/problem/1991
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
using namespace std;

int n;
vector<pair<char, pair<char, char>>> matrix;
map<char, pair<char, char>> m;


void preorderTraversal(int index) {
	auto i = m['A'];
	stack<char> st;
	st.push('A');
	while (!st.empty()) {
		cout << st.top(); st.pop();
		if (i.first != '.') {
			cout << i.first;
			if (i.second != '.') st.push(i.second);
			i = m[i.first];
			continue;
		}
		if (i.second != '.') {
			cout << i.second;
			i = m[i.second];
			continue;
		}
		i = m[st.top()]; st.pop();
	}
	
	//
	//auto edge = matrix[index];
	//for (auto it = edge.begin(); it != edge.end(); it++) {
	//	if (it == edge.begin()) {
	//		cout << *it;
	//	} else if (*it != '.') {
	//		int nextIndex;
	//		for (int i = 0; i < n; i++) {
	//			if (*matrix[i].begin() == *it){
	//				nextIndex = i;
	//				break;
	//			}
	//		}
	//		preorderTraversal(nextIndex);
	//	} else
	//		continue;
	//}
}
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
		char ch[3];
		for (int j = 0; j < 3; j++)
			cin >> ch[j];
		m[ch[0]].first = ch[1];
		m[ch[0]].second = ch[2];
	}

	//calc
	preorderTraversal(0);
	cout << "\n";
	
	return 0;
}