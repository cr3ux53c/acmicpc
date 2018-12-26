//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
	std::string str("This is an example sentence.");
	std::cout << str << '\n';
	// "This is an example sentence."
	str.insert(str.size()+1, "a");
	std::cout << str << '\n';
	
	
	str.erase(1, 1);                        //            ^^^^^^^^
	std::cout << str << '\n';
	
	str.erase(10, 8);                        //            ^^^^^^^^
	std::cout << str << '\n';
	// "This is an sentence."
	str.erase(str.begin() + 9);               //           ^
	std::cout << str << '\n';
	// "This is a sentence."
	str.erase(str.begin() + 5, str.end() - 9);  //       ^^^^^
	std::cout << str << '\n';
	// "This sentence."
	return 0;
}