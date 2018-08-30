#pragma warning (disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <assert.h>
#include <map>
using namespace std;

vector<int> v(5);

void func(int i) {
	//assert(i < v.size() && "fdsa");
	//_ASSERT(i < v.size() && "f3f3f");
	//_ASSERT_EXPR(i < v.size(), "fdsa");
	_STL_ASSERT(i < v.size(), "what's up?");
	cout << v[i];
}

int main() {
	map<string, string> m;
	bool b;
	 m.insert(pair<string, string>("hat", "a"));
	m.insert(pair<string, string>("hat", "b"));
	m.insert(pair<string, string>("h", "c"));
	m.insert(pair<string, string>("h", "d"));
	cout << m.size();
	for (auto iter = m.begin(); iter != m.end(); ++iter){

			cout << (*iter).first << ", " << (*iter).second << endl;
	}

	return 0;
}