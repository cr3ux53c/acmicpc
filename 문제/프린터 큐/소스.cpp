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
		//문서의 수, 100이하 / 몇 번째로 인쇄되었는지 궁금한 문서가 현재 Queue의 어떤 위치에 있는지를 알려주는 M(0이상 N미만)이 주어진다.
		int n, m, topPriority = 0;
		cin >> n >> m;
		//중요도 입력: N개 문서의 중요도가 주어지는데, 중요도는 적절한 범위의 int형으로 주어진다. 중요도가 같은 문서가 여러 개 있을 수도 있다. 
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