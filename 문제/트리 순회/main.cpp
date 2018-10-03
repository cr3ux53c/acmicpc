//https://www.acmicpc.net/problem/1991
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
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

	set<int> edge;
	vector<set<char>> mat(n, set<char>());
	map<char, pair<char, char>> m;
	pair<char, char> p;
	vector<char> parent;
	parent.push_back('R');
	parent.push_back('A');
	parent.push_back('B');
	parent.push_back('C');
	parent.push_back('E');
	parent.push_back('F');
	parent.push_back('D');

	p.first = 'B';
	p.second = 'C';
	m['A'] = p;
	p.first = 'D';
	p.second = '.';
	m['B'] = p;
	p.first = 'E';
	p.second = 'F';
	m['C'] = p;
	p.first = '.';
	p.second = '.';
	m['E'] = p;
	p.first = '.';
	p.second = '.';
	m['F'] = p;
	p.first = '.';
	p.second = '.';
	m['D'] = p;

	stack<map<char, pair<char, char>>::iterator> st;
	
	do {
		if (m[0].first != 'A') {

		}

	} while (st.empty() != NULL);

	do {

		for (auto it = m.begin(); it != m.end(); it++) {
			if ((*it).first != '.') {
				st.push(it);
				it = m[(*it).first]
			}
		}
		
	} while (st.empty() != NULL);



	stack<map<char, pair<char, char>>> st;
	st.push(m);

	while (!st.empty()) {
		if (m['R'].first != '.') {

		} else {
			
		}
	}




	

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
	pair<int, int> a;
	return 0;
}