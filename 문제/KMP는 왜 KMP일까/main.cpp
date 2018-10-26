//https://www.acmicpc.net/problem/2902
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main(int argc, char* argv[]) { 
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	string s; cin >> s;
	stringstream ss;
	int offset = 0; // 0¹øÂ°
	ss << s[offset];

	while (offset < s.size()) {
		offset = s.find('-', offset+1);
		if (offset == string::npos) break;
		ss << s[offset+1];
	}

	cout << ss.str();

	return 0;
}