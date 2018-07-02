//로봇 청소기
//시간 제한		메모리 제한		제출	정답	맞은 사람	정답 비율
//		2 초		512 MB		6677	3167		2152		48.787%
//https://www.acmicpc.net/problem/14503
//1현재 위치를 청소한다.
//2현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
//  1왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
//  2왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
//  3네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
//  4네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
#pragma warning(disable:4996)
#include <stdio.h>
#include <malloc.h>

enum { NOURTH, EAST, SOUTH, WEST };

int main() {
	int r, c, x, y, d;
	int number = 0;

	scanf("%d %d %d %d %d", &r, &c, &y, &x, &d);

	int** matrix = (int**)malloc(sizeof(int*)*r);
	for (int i = 0; i < r; i++) {
		matrix[i] = (int*)malloc(sizeof(int)*c);
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int input;
			scanf("%d", &input);
			matrix[i][j] = input;
			if (input == 0) number++;
		}
	}

	matrix[x][y] = 1; number--;
	
	while(1){
		int currentD = d;
		for (int i=0;i<4;i++){
			if (matrix[x--][y] == 0) {
				x--;
				d--; if (d < 0) d = WEST;
				matrix[x][y] = 1;
				break;
			} else {
				d--; if (d < 0) d = WEST;
			}
		}
		//if (currentD == d) 
	}
	


	for (int i = 0; i < c; i++)
		free(matrix[i]);
	free(matrix);
	return 0;
}