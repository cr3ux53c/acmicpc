//https://www.acmicpc.net/problem/2661
#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

class vertex {
public:
	vector<int> arr;
	int index;
	vertex(int i) {
		arr = vector<int>();
		arr.push_back(i);
		index = ::idx++;
	}
	~vertex() {
	}
};

vector<list<vertex>> adjacentList;
int n; //N은 1 이상 80 이하이다.
int idx = 0;

void makeAdjacentList(int i) {
	vector<bool> visited(0);
	adjacentList[0].push_back(vertex(0));
	adjacentList[1].push_back(vertex(1));
	adjacentList[1].push_back(vertex(2));
	adjacentList[1].push_back(vertex(3));

	stack<int> st;
	st.push(i);

	while (!st.empty()) {
		i = st.top(); st.pop();



	}

	
}

int main() {
	
	cin >> n;



	return 0;
}