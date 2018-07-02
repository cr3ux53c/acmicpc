//�κ� û�ұ�
//�ð� ����		�޸� ����		����	����	���� ���	���� ����
//		2 ��		512 MB		6677	3167		2152		48.787%
//https://www.acmicpc.net/problem/14503
//1���� ��ġ�� û���Ѵ�.
//2���� ��ġ���� ���� ������ �������� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�.
//  1���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
//  2���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.
//  3�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
//  4�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
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