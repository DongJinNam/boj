#include <stdio.h>

bool bCheck[15][15];
int N;
long long cnt = 0;

void go(int);
bool check(int, int);

int main() {
	scanf("%d", &N);
	go(0);
	printf("%lld\n", cnt);
	return 0;
}

void go(int row) {
	if (row == N) {
		cnt++;
		return;
	}
	for (int col = 0; col < N; col++) {
		bCheck[row][col] = true;
		if (check(row, col)) {
			go(row + 1);
		}
		bCheck[row][col] = false;
	}
}

bool check(int row, int col) {
	int y, x;
	// 세로
	for (int i = 0; i < N; i++) {
		if (i == row) continue;
		if (bCheck[i][col] == true)
			return false;
	}
	// 왼쪽 위 대각선
	y = row - 1;
	x = col - 1;
	while (y >= 0 && x >= 0) {
		if (bCheck[y][x] == true) {
			return false;
		}
		y--;
		x--;		
	}	
	// 오른쪽 위 대각선
	y = row - 1;
	x = col + 1;
	while (y >= 0 && x < N) {
		if (bCheck[y][x] == true) {
			return false;
		}
		y--;
		x++;
	}
	return true;
}