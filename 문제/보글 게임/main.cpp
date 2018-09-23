#include <iostream>
#include <string>
using namespace std;

//const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
//const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };
const int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

char matrix[][6] = {
	"URLPM",
	"XPRET",
	"GIAET",
	"XTNZY",
	"XOQRS",
};

bool hasWord(int y, int x, char* word) {
	//baseCase
	if (word[0] != matrix[y][x])
		return false;
	if (strlen(word) == 1) {
		cout << "TRUE";
		return true;
	}
	//calc
	for (int i = 0; i < 8; i++) {
		if (hasWord(y + dy[i], x + dx[i], word + 1)) {
		}
	}
}

int main(int argc, char *argv[]) {
	char word[] = "ENA";
	hasWord(2, 3, word);
	return 0;
}