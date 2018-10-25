//https://www.acmicpc.net/problem/1753
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

enum {U, V, W};

int main(int argc, char* argv[]) { 
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int v, e, k; cin >> v >> e >> k;
	vector<vector<int>> adjList = vector<vector<int>>(e, vector<int>(3));
	vector<int> comulativeWeight(v, INT32_MAX);

	for (int i = 0; i < e; i++) {
		int u, v, w; cin >> u >> v >> w;
		adjList[i][U] = u;
		adjList[i][V] = v;
		adjList[i][W] = w;
	}

	int start = k;
	int result = 0;

	for (int i = 0; i < e; i++) {

		if (adjList[i][U] == start) {
			comulativeWeight[adjList[i][V]-1] = min(adjList[i][W], comulativeWeight[adjList[i][V]]);
		}
		
		if (comulativeWeight[i] == INT32_MAX)
			if (i == 0) cout << "0\n";
			else cout << "INF\n";
		else
			cout << comulativeWeight[i] << "\n";
	}

	return 0;
}