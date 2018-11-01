//https://www.acmicpc.net/problem/1753
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <deque>
using namespace std;

enum {U, V, W};

int main(int argc, char* argv[]) { 
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int v, e, k; cin >> v >> e >> k;
	vector<vector<int>> adjList = vector<vector<int>>(e, vector<int>(3));
	vector<int> comulativeWeight(v, INT32_MAX);

	for (int i = 0; i < e; i++) {
		int u, v, w; cin >> u >> v >> w;
		if (v == k) continue;
		adjList[i][U] = u;
		adjList[i][V] = v;
		adjList[i][W] = w;
	}

	comulativeWeight[k-1] = 0;
	deque<int> q;
	q.push_back(k);
	
	while (!q.empty()) {
		int start = q.front(); q.pop_front();

		for (int i = 0; i < e; i++) {
			if (adjList[i][U] == start) {
				if (find(q.begin(), q.end(), adjList[i][V]) == q.end()) {
					q.push_back(adjList[i][V]);
				}
				comulativeWeight[adjList[i][V]-1] = min(comulativeWeight[start-1] + adjList[i][W], comulativeWeight[adjList[i][V] - 1]);
			}
		}
	}

	//output
	for (int i = 0; i < comulativeWeight.size(); i++) 
		if (comulativeWeight[i] == INT32_MAX)
			cout << "INF\n";
		else
			cout << comulativeWeight[i] << '\n';

	return 0;
}