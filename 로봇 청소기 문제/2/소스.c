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

	matrix[rr][rc] = CLEAN; count++; //ó�� ������ û�Ҹ� �ѹ� �Ѵ�.

	while (1) {
		int currentD = d;
		for (int i = 0; i < 4; i++) { // �溸�� ������ ����.
			int forwardrr = rr, forwardrc = rc; //���� ���� ��ǥ
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
			if (matrix[forwardrr][forwardrc] == UNCLEAN) { //���ʿ� û�Ұ� ���� �ȉ�����
				d--; if (d < 0) d = WEST; //����.
				switch (d) {//����
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
				count++; matrix[rr][rc] = CLEAN;//û���Ѵ�
				break;
			}
			else {
				d--; if (d < 0) d = WEST;
			}
			if (currentD == d) { //����ʰ� �� ��
				switch (d) {//�ڷ� �����Ѵ�
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
				if (matrix[rr][rc] == WALL) { //������ �ڸ��� ���̸� ��� ��� �� ����
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