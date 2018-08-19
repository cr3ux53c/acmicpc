#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
	string s;
	string a = "fa";
	s.push_back('[');
	s.push_back('1');
	s.push_back('a');
	s.push_back(a[0]);
	cout << s;

	return 0;
}