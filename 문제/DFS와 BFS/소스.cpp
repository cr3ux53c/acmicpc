//https://www.acmicpc.net/problem/1260
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
using namespace std;

int n, m, v;
vector<list<int>> adjacentList;
vector<bool> visited;
vector<bool> discovered;

void dfs(vector<int> *result, int here) {
	result->push_back(here);
	visited[here] = true;
	list<int>::iterator it;
	for (it = adjacentList[here].begin(); it != adjacentList[here].end(); it++) {
		int there = *it;
		if (!visited[there]) {
			dfs(result, there);
		}
	}
}

vector<int> bfs(int start) {
	queue<int> q;
	vector<int> order;
	list<int>::iterator it;
	discovered[start] = true;
	q.push(start);
	while (!q.empty()) {
		int here = q.front(); q.pop();
		order.push_back(here);
		for (it = adjacentList[here].begin(); it != adjacentList[here].end(); it++) {
			int there = *it;
			if (!discovered[there]) {
				q.push(there);
				discovered[there] = true;
			}
		}
	}
	return order;
}

void makeAdjList(vector<list<int>> *adj) {
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		//�� ������ ���� �� �־��� ���� �ִµ�, ������ �ϳ��� �ִ� ������ �����ϸ� �ȴ�.
		(*adj)[x].push_back(y);
		//�Է����� �־����� ������ ������̴�.
		(*adj)[y].push_back(x);
	}

	//�湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮
	for (int i = 0; i < n; i++) {
		adjacentList[i].sort();
	}
}

int main() {
	// ������ ���� N(1 �� N �� 1,000), ������ ���� M(1 �� M �� 10,000), Ž���� ������ ������ ��ȣ V
	//input
	cin >> n >> m >> v;
	//���� ��ȣ�� 1������ N�������̴�.
	adjacentList = vector<list<int>>(n + 1, list<int>());
	visited = vector<bool>(n + 1);
	discovered = vector<bool>(n + 1);
	makeAdjList(&adjacentList);

	//calc
	vector<int> dfsResult;
	dfs(&dfsResult, v);

	vector<int> bfsResult = bfs(v);

	//output
	for (int i = 0; i < dfsResult.size(); i++) {
		cout << dfsResult[i] << (dfsResult.size() == i + 1 ? "" : " ");
	}
	cout << "\n";
	for (int i = 0; i < bfsResult.size(); i++) {
		cout << bfsResult[i] << (bfsResult.size() == i + 1 ? "" : " ");
	}
	return 0;
}