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
		//������ ��, 100���� / �� ��°�� �μ�Ǿ����� �ñ��� ������ ���� Queue�� � ��ġ�� �ִ����� �˷��ִ� M(0�̻� N�̸�)�� �־�����.
		int n, m;
		queue<int> q;
		vector<int> priority;
		cin >> n >> m;
		//�߿䵵 �Է�: N�� ������ �߿䵵�� �־����µ�, �߿䵵�� ������ ������ int������ �־�����. �߿䵵�� ���� ������ ���� �� ���� ���� �ִ�. 
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