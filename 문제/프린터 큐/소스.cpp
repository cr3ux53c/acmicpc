//https://www.acmicpc.net/problem/1966
#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main() {
	//input
	int testCase;
	cin >> testCase;
	
	//loop
	for (int i = 0; i < testCase; i++) {
		//문서의 수, 100이하 / 몇 번째로 인쇄되었는지 궁금한 문서가 현재 Queue의 어떤 위치에 있는지를 알려주는 M(0이상 N미만)이 주어진다.
		int n, m;
		queue<int> q;
		vector<int> priority;
		cin >> n >> m;
		//중요도 입력: N개 문서의 중요도가 주어지는데, 중요도는 적절한 범위의 int형으로 주어진다. 중요도가 같은 문서가 여러 개 있을 수도 있다. 
		for (int j = 0; j < n; j++) {
			int input;
			cin >> input;
			q.push(input);
			priority.push_back(input);
		}
		sort(priority.rbegin(), priority.rend());
		//priority.erase(unique(priority.begin(), priority.end()), priority.end());
		
		int priorityIndex = 0, count = 0;
		while (!q.empty()) {
			if (q.front() < priority[priorityIndex]) {
				q.push(q.front());
				q.pop();
				if (m == 0) m = q.size() - 1; else m--;
			} else {
				q.pop();
				count++;
				priorityIndex++;
				if (m == 0) break; else m--;
			}
		}
		cout << count << '\n';
	}
	return 0;
}	