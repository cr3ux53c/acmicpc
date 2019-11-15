#include <iostream>
#include <string>
#include <deque>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	int n, m; // 1 <= m <= n <= 50
	cin >> n >> m;

	deque<int> d;
	queue<int> q;

	for (int i = 0; i < m; i++) {
		int input;
		cin >> input;
		q.push(input);
	}

	for (int i = 1; i <= n; i++)
		d.push_back(i);

	int count = 0;

	while (!q.empty()) {
		int index;
		for (int i = 0; i < d.size(); i++) {
			if (q.front()==d[i]){
				index = i+1;
			}
		}
		if (index <= floor(d.size()/2.0+0.5)) {
			while (q.front() != d.front()) {
				d.push_back(d.front());
				d.pop_front();
				count++;
			}
			d.pop_front();
			q.pop();
		} else {
			while (q.front() != d.front()) {
				d.push_front(d.back());
				d.pop_back();
				count++;
			}
			d.pop_front();
			q.pop();
		}
	}
	cout << count;
	return 0;
}