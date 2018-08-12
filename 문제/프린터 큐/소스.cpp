//https://www.acmicpc.net/problem/1966
#include <iostream>
#include <queue>
using namespace std;

vector<queue<int>> q;

int main() {
	//input
	int testCase;
	cin >> testCase;
	q = vector<queue<int>>(testCase);

	for (int i = 0; i < testCase; i++) {
		//������ ��, 100���� / �� ��°�� �μ�Ǿ����� �ñ��� ������ ���� Queue�� � ��ġ�� �ִ����� �˷��ִ� M(0�̻� N�̸�)�� �־�����.
		int n, m, topPriority = 0;
		cin >> n >> m;
		//�߿䵵 �Է�: N�� ������ �߿䵵�� �־����µ�, �߿䵵�� ������ ������ int������ �־�����. �߿䵵�� ���� ������ ���� �� ���� ���� �ִ�. 
		for (int j = 0; j < n; j++) {
			int input;
			cin >> input;
			q[i].push(input);
			if (topPriority < input) topPriority = input;
		}

		auto count = 0;
		while (q[i].size() > m+1) {
			if (q[i].front() < topPriority) {
				q[i].push(q[i].front());
				q[i].pop();
			} else {
				q[i].pop();
				count++;
			}

		}
		cout << count;
	}






	return 0;
}