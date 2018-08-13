//https://www.acmicpc.net/problem/11866
#include <iostream>
#include <queue>
using namespace std;

int jump(queue<int> *q, int count){
	for (int i = 0; i < count; i++) {
		q->push(q->front());
		q->pop();
	}
	return q->front();
}

int main() {
	//(1 ¡Â M ¡Â N ¡Â 1,000)
	int n, m;
	cin >> n >> m;
	queue<int> q;

	for (int i = 1; i <= n; i++)
		q.push(i);
	
	cout << '<';
	while (!q.empty()) {
		cout << jump(&q, m - 1);
		q.pop();
		if (q.empty()) cout << '>'; else cout << ", ";
	}
	
	return 0;
}