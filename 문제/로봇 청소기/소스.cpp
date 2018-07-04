//문제
//로봇 청소기가 주어졌을 때, 청소하는 영역의 개수를 구하는 프로그램을 작성하시오.
//로봇 청소기가 있는 장소는 N×M 크기의 직사각형으로 나타낼 수 있으며, 1×1크기의 정사각형 칸으로 나누어져 있다.각각의 칸은 벽 또는 빈 칸이다.청소기는 바라보는 방향이 있으며, 이 방향은 동, 서, 남, 북중 하나이다.지도의 각 칸은(r, c)로 나타낼 수 있고, r은 북쪽으로부터 떨어진 칸의 개수, c는 서쪽으로 부터 떨어진 칸의 개수이다.
//로봇 청소기는 다음과 같이 작동한다.
//
//1. 현재 위치를 청소한다.
//2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
//  1. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
//  2. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
//  3. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
//  4. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
//로봇 청소기는 이미 청소되어있는 칸을 또 청소하지 않으며, 벽을 통과할 수 없다.
//
//입력
//첫째 줄에 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 50)
//둘째 줄에 로봇 청소기가 있는 칸의 좌표(r, c)와 바라보는 방향 d가 주어진다.d가 0인 경우에는 북쪽을, 1인 경우에는 동쪽을, 2인 경우에는 남쪽을, 3인 경우에는 서쪽을 바라보고 있는 것이다.
//셋째 줄부터 N개의 줄에 장소의 상태가 북쪽부터 남쪽 순서대로, 각 줄은 서쪽부터 동쪽 순서대로 주어진다.빈 칸은 0, 벽은 1로 주어진다.장소의 모든 외곽은 벽이다.
//로봇 청소기가 있는 칸의 상태는 항상 빈 칸이다.
//출력
//로봇 청소기가 청소하는 칸의 개수를 출력한다.

//https://www.acmicpc.net/problem/14503

#include <stdio.h>
#include <malloc.h>
#include <conio.h>

enum { NORTH, EAST, SOUTH, WEST };
enum { UNCLEAN, WALL, CLEAN };

int main() {
	int r, c, rr, rc, d, count = 0;

	scanf_s("%d %d %d %d %d", &r, &c, &rr, &rc, &d);

	//동적 배열 할당
	int** matrix = (int**)malloc(sizeof(int*)*r);
	for (int i = 0; i < r; i++) {
		matrix[i] = (int*)malloc(sizeof(int)*c);
	}

	//입력값 할당
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
			if (matrix[forwardrr][forwardrc] == UNCLEAN) { //왼쪽에 청소가 아직 안瑛만
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
				//printf("(%d, %d) 청소 함\n", rr, rc);
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
