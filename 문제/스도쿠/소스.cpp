//https://www.acmicpc.net/problem/2580

#include <iostream>
#include <stack>

using namespace std;

const int BITMASK[] = { 0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };

class POINT {
public:
	int x, y;
	POINT(int x, int y) {
		this->x = x; this->y = y;
	}
	POINT() {
		this->x = -1; this->y = -1;
	}
};

//함수 정방향 선언
int* getNumbers(int const matrix[9][9], POINT p, bool isHorizontal);
int* getNumbersInSmallSquare(int const matrix[9][9], POINT p);
stack<int> getDuplicatedNumbers(int c[], int v[], int s[]);


int main() {
	//입력
	int matrix[9][9];
	POINT emptyPositions[81];
	int input, count = 0;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			cin >> input;
			matrix[i][j] = input;
			if (input == 0) {
				emptyPositions[++count].x = j;
				emptyPositions[count].y = i;
			}

		}

	for (int i = 0; i < count; i++) {
		if (matrix[emptyPositions[i].y][emptyPositions[i].x] == 0) {
			stack<int> numbers = getDuplicatedNumbers(getNumbers(matrix, p, true), getNumbers(matrix, p, false), getNumbersInSmallSquare(matrix, p));
			numbers.size();

		}
	}

	//출력
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << matrix[i][j];
			if (j < 8) cout << " ";
		}
		cout << endl;
	}
	return 0;
}

int* getNumbers(int const matrix[9][9], POINT p, bool isHorizontal) {
	int* numbers = new int[9];
	int idx = 0;
	int i = 0;
	int* x;
	int* y;

	if (isHorizontal) {
		x = &i; y = &p.y;
	} else {
		y = &i; x = &p.x;
	}

	for (; i < 9; i++) {
		if (matrix[*y][*x] != 0) {
			numbers[idx++] = matrix[*y][*x];
		}
	}
	numbers[idx] = 0;
	return numbers;
}

int* getNumbersInSmallSquare(int const matrix[9][9], POINT p) {
	int* numbers = new int[9];
	int idx = 0;
	int row = 3 * (int)((p.x) / 3);
	int col = 3 * (int)((p.y) / 3);
	for (int i = row; i <= row+2; i++) {
		for (int j = col; j <= col+2; j++) {
			if (matrix[j][i] != 0) {
				numbers[idx++] = matrix[j][i];
			}
		}
	}
	numbers[idx] = 0;
	return numbers;
}

stack<int> getDuplicatedNumbers(int c[], int v[], int s[]) {
	unsigned int a = 0;
	for (int i = 0; c[i] > 0; i++) {
		a |= BITMASK[c[i]];
	}
	for (int i = 0; v[i] > 0; i++) {
		a |= BITMASK[v[i]];
	}
	for (int i = 0; s[i] > 0; i++) {
		a |= BITMASK[s[i]];
	}
	
	stack<int> numbers;
	





	for (int i = 0; i < 9; i++) {
		
	}

	for (int i = 0; c[i] > 0; i++) {
		for (int j = 0; v[j] > 0; j++) {
			for (int k = 0; s[k] > 0; k++) {
				if (c[i] == v[j] && v[j] == s[k]) {
					numbers.push(s[k]);
				}
			}
		}
	}

	return numbers;
}