//https://www.acmicpc.net/problem/2252
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

struct func {
	bool operator()() {
		return true;
	}
};

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;
	list<int> order(n);

	int i = 1;
	for (auto it = order.begin(); it != order.end(); it++) {
		*it = i++;
	}

	sort(order.begin(), order.end(), func()	);

	/*for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		if (distance(order.begin(), find(order.begin(), order.end(), a)) > distance(order.begin(), find(order.begin(), order.end(), b))) {
			order.insert(order.begin(), a);
		}
	}*/

	


	return 0;
}