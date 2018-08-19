#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
	std::stringstream ss;
	ss << "my data " << 42;
	std::string myString(ss.str());
	cout << myString;
	return 0;
}