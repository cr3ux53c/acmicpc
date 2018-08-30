//https://www.acmicpc.net/problem/9375
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct set {
	string name;
	int count;
	set(string name, int count) {
		this->name = name;
		this->count = count;
	}
};

int main() {
	int t;
	cin >> t;

	//testCases
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		
		vector<set> s;

		for (int j = 0; j < n; j++) {
			string name, sort;
			cin >> name >> sort;
			if (s.size() == 0) {
				s.push_back(set(sort, 1));
			} else {
				bool isSort = false;
				for (auto i = s.begin(); i != s.end(); i++) {
					if ((*i).name.compare(sort) == 0) {
						(*i).count++;
						isSort = true;
						break;
					}
				}
				if (isSort == false) {
					s.push_back(set(sort, 1));
				}
			}
		}

		int sum = 1;
		for (auto i = s.begin(); i != s.end(); i++)
			sum *= (*i).count + 1;
		cout << sum - 1 << '\n';

	}
	return 0;
}