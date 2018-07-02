#include <stdio.h>
#include <malloc.h>
#include <conio.h>

enum { NORTH, EAST, SOUTH, WEST };
enum { UNCLEAN, WALL, CLEAN };

int main() {
	int r, c, rr, rc, d, count = 0;

	scanf_s("%d %d %d %d %d", &r, &c, &rr, &rc, &d);

	int** matrix = (int**)malloc(sizeof(int*)*r);
	for (int i = 0; i < r; i++) {
		matrix[i] = (int*)malloc(sizeof(int)*c);
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int input;
			scanf_s("%d", &input);
			matrix[i][j] = input;
		}
	}

	matrix[rr][rc] = CLEAN; count++; //처음 무조건 청소를 한번 한다.

	while (1) {
		int currentD = d;
		for (int i = 0; i < 4; i++) { // 길보일 때까지 돈다.
			int forwardrr = rr, forwardrc = rc; //왼쪽 앞의 좌표
			switch (d) {
			case NORTH:
				forwardrc--;
				break;
			case WEST:
				forwardrr++;
				break;
			case SOUTH:
				forwardrc++;
				break;
			case EAST:
				forwardrr--;
				break;
			}
			if (matrix[forwardrr][forwardrc] == UNCLEAN) { //왼쪽에 청소가 아직 안됬으면
				d--; if (d < 0) d = WEST; //돈다.
				switch (d) {//간다
				case NORTH:
					rr--;
					break;
				case WEST:
					rc--;
					break;
				case SOUTH:
					rr++;
					break;
				case EAST:
					rc++;
					break;
				}
				count++; matrix[rr][rc] = CLEAN;//청소한다
				break;
			}
			else {
				d--; if (d < 0) d = WEST;
			}
			if (currentD == d) { //사면초가 일 때
				switch (d) {//뒤로 후진한다
				case NORTH:
					rr++;
					break;
				case WEST:
					rc++;
					break;
				case SOUTH:
					rr--;
					break;
				case EAST:
					rc--;
					break;
				}
				if (matrix[rr][rc] == WALL) { //후진한 자리가 벽이면 결과 출력 및 종료
					printf("%d", count);
					for (int i = 0; i < c; i++)
						free(matrix[i]);
					free(matrix);
					_getch();
					return 0;
				}
				else {
					break;
				}
			}
		}
	}
}