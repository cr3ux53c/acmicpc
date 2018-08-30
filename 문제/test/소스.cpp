#pragma warning (disable:4996)
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <assert.h>
#include <map>
#include <chrono>
#include <thread>
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
	char a = 0;
	
	while(1){
		_STL_ASSERT(a != CHAR_MAX, "");
		cout << (int)a++ << " ";
		this_thread::sleep_for(chrono::milliseconds(50));
	}

	return 0;
}