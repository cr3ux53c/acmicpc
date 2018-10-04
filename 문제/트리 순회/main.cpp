//https://www.acmicpc.net/problem/1991
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n;
map<char, pair<char, char>> m;

void preorder(char ch) {
	cout << ch;
	if (m[ch].first != '.')
		preorder(m[ch].first);
	if (m[ch].second != '.')
		preorder(m[ch].second);
}

void inorder(char ch) {
	if (m[ch].first != '.')
		inorder(m[ch].first);
	cout << ch;
	if (m[ch].second != '.')
		inorder(m[ch].second);
}

void postorder(char ch) {
	if (m[ch].first != '.')
		postorder(m[ch].first);
	if (m[ch].second != '.')
		postorder(m[ch].second);
	cout << ch;
}

int main(int argc, char* argv[]) { 
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	//input
	cin >> n;
	for (int i = 0; i < n; i++) {
		char ch[3];
		for (int j = 0; j < 3; j++)
			cin >> ch[j];
		m[ch[0]].first = ch[1];
		m[ch[0]].second = ch[2];
	}

	//calc
	vector<void*> funcA = { preorder, inorder, postorder };
	void(*order)(char);
	for (auto f : funcA) {
		order = (void(*)(char))f;
		order('A'); cout << '\n';
	}
	
	return 0;
}