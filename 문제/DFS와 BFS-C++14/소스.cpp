//https://www.acmicpc.net/problem/1260
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;

int n, m, v;
vector<list<int>> adjacentList;
vector<bool> visited;
vector<bool> discovered;

void dfs(vector<int> *result, int here) {
	result->push_back(here);
	visited[here] = true;
	for (auto it = adjacentList[here].begin(); it != adjacentList[here].end(); it++) {
		int there = *it;
		if (!visited[there]) {
			dfs(result, there);
		}
	}
}

void dfsIterative(vector<int> *result, int s) {
	stack<int> st;
	st.push(s);
	while (!st.empty()) {
		s = st.top(); st.pop();
		if (visited[s]) {
			continue;
		}
		visited[s] = true;
		result->push_back(s);
		for (auto it = adjacentList[s].rbegin(); it != adjacentList[s].rend(); it++) {
			if (!visited[*it]) {
				st.push(*it);
			}
		}
	}
}

vector<int> bfs(int start) {
	queue<int> q;
	vector<int> order;
	discovered[start] = true;
	q.push(start);
	while (!q.empty()) {
		int here = q.front(); q.pop();
		order.push_back(here);
		for (auto it = adjacentList[here].begin(); it != adjacentList[here].end(); it++) {
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
		//한 간선이 여러 번 주어질 수도 있는데, 간선이 하나만 있는 것으로 생각하면 된다.
		(*adj)[x].push_back(y);
		//입력으로 주어지는 간선은 양방향이다.
		(*adj)[y].push_back(x);
	}

	//방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문
	for (int i = 0; i < n; i++) {
		adjacentList[i].sort();
	}
}

int main() {
	// 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V
	//input
	cin >> n >> m >> v;
	//정점 번호는 1번부터 N번까지이다.
	adjacentList = vector<list<int>>(n + 1, list<int>());
	visited = vector<bool>(n + 1);
	discovered = vector<bool>(n + 1);
	makeAdjList(&adjacentList);

	//calc
	vector<int> dfsResult;
	dfs(&dfsResult, v);
	//dfsIterative(&dfsResult, v);
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