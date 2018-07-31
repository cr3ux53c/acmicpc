//https://www.acmicpc.net/problem/2580

#include <iostream>
#include <stack>

using namespace std;

//    int BITMASK[] = { 0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };
const int BITMASK[] = { 0, 1, 2, 4, 8, 16, 32, 64, 128, 256 };
				//		0  1  2  3  4   5   6   7    8    9

class POINT {
public:
	int* candidate;
	int x, y;
	POINT(int y, int x) {
		this->x = x; this->y = y;
		candidate = NULL;
	}
	POINT() {
		this->x = -1; this->y = -1;
		candidate = NULL;
	}
};

//함수 정방향 선언
unsigned int* getNumbers(int const matrix[9][9], POINT *p, bool isHorizontal);
unsigned int* getNumbersInSmallSquare(int const matrix[9][9], POINT *p);
int* getCandidates(unsigned int c[], unsigned int v[], unsigned int s[]);

int matrix[9][9];
int candidate[9];
POINT emptyPositions[81];


int main() {
	//입력
	
	int input, count = 0;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			cin >> input;
			matrix[i][j] = input;
			if (input == 0) {
				emptyPositions[count].x = j;
				emptyPositions[count++].y = i;
			}

		}

	for (int i = 0; i < count; i++) {
		POINT p(emptyPositions[i].y, emptyPositions[i].x);
		emptyPositions[i].candidate = getCandidates(getNumbers(matrix, &p, true), getNumbers(matrix, &p, false), getNumbersInSmallSquare(matrix, &p));
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

unsigned int* getNumbers(int const matrix[9][9], POINT *p, bool isHorizontal) {
	unsigned int* numbers = new unsigned int[9];
	int idx = 0;
	int i = 0;
	int* x;
	int* y;

	if (isHorizontal) {
		x = &i; y = &(p->y);
	} else {
		y = &i; x = &(p->x);
	}

	for (; i < 9; i++) {
		if (matrix[*y][*x] != 0) {
			numbers[idx++] = matrix[*y][*x];
		}
	}
	numbers[idx] = NULL;
	return numbers;
}

unsigned int* getNumbersInSmallSquare(int const matrix[9][9], POINT *p) {
	unsigned int* numbers = new unsigned int[9];
	int idx = 0;
	int row = 3 * (int)((p->x) / 3);
	int col = 3 * (int)((p->y) / 3);
	for (int i = row; i <= row+2; i++) {
		for (int j = col; j <= col+2; j++) {
			if (matrix[j][i] != 0) {
				numbers[idx++] = matrix[j][i];
			}
		}
	}
	numbers[idx] = NULL;
	return numbers;
}

int* getCandidates(unsigned int c[], unsigned int v[], unsigned int s[]) {
	unsigned int a = 0;
	for (int i = 0; c[i] != NULL; i++) {
		a |= BITMASK[c[i]];
	}
	for (int i = 0; v[i] != NULL; i++) {
		a |= BITMASK[v[i]];
	}
	for (int i = 0; s[i] != NULL; i++) {
		a |= BITMASK[s[i]];
	}

	int *numbers = (int*)malloc(sizeof(int) * 9);
	int idx = 0;
	for (unsigned int i = 1; i <= 9; i++) {
		if (!(a & BITMASK[i])) {
			numbers[idx++] = i;
		}
	}
	numbers[idx] = NULL;
	
	return numbers;
}