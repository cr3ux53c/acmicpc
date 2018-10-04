//https://www.acmicpc.net/problem/2178
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

enum XY { Y, X };
const int D[][4] = {
//	  동,서,남,북
	{ 0, 0, 1, -1 },
	{ 1, -1, 0, 0} ,
};

int main(int argc, char* argv[]) { 
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	//input
	int n, m, result = INT32_MAX;
	cin >> n >> m;
	vector<vector<int>> map(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.size(); j++)
			map[i][j] = s[j] - '0';
	}

	//calc
	stack<pair<int, int>> st;
	st.push({ 0, 0 });
	while (st.empty() == false) {
		auto pos = st.top(); st.pop();

		//baseCase
		if (map[pos.first][pos.second] == 0)
			continue;
		if (pos.first == n-1 && pos.second == m-1) {
			result = min(result, map[pos.first][pos.second]);
			/*if (st.empty() == false)
				continue;
			else
				break;*/
		}

		//동서남북
		for (int i = 0; i < 4; i++) {
			//Overflow check
			if (pos.first + D[Y][i] < 0 || pos.first + D[Y][i] >= n)
				continue;
			if (pos.second + D[X][i] < 0 || pos.second + D[X][i] >= m)
				continue;
			if (map[pos.first + D[Y][i]][pos.second + D[X][i]] == 0)
				continue;
			if (map[pos.first+ D[Y][i]][pos.second+ D[X][i]] > 1) { // 다음 좌표가 1 초과면
				map[pos.first + D[Y][i]][pos.second + D[X][i]] = min(map[pos.first + D[Y][i]][pos.second + D[X][i]], map[pos.first][pos.second] +1);
			} else if (map[pos.first + D[Y][i]][pos.second + D[X][i]] == 1){
				map[pos.first + D[Y][i]][pos.second + D[X][i]] += map[pos.first][pos.second];
			}
			st.push({ pos.first + D[Y][i], pos.second+ D[X][i] });
		}
		map[pos.first][pos.second] = 0;
	}

	cout << result;
	return 0;
}

//3 5
//10111
//11101
//00111