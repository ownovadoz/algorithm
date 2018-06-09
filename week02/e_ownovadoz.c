#include <stdio.h>

#define MAX 128

int N;
int matrix[MAX][MAX];
int color[2] = { 0, };

void solution(int x, int y, int size) {
	int c = matrix[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (matrix[i][j] != c) {
				int resize = size / 2;
				solution(x, y, resize);
				solution(x, y + resize, resize);
				solution(x + resize, y, resize);
				solution(x + resize, y + resize, resize);
				return;
			}
		}
	}
	color[c]++;
}

int main(void) {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	solution(0, 0, N);
	printf("%d\n%d", color[0], color[1]);

	return 0;
}