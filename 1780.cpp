#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>

#define MAX 3000

int board[MAX][MAX];
int cnt_arr[3] = { 0,0,0 }; // -1,0,1 종이 개수

// 재귀를 통한 분할 정복 문제
void go(int start_x, int start_y, int size) {
	if (size == 1) { // 끝내는 조건
		cnt_arr[board[start_y][start_x] + 1]++;
		return;
	}		
	// 영역 내에서 모두
	bool bStop = true;
	for (int i = start_y; i < start_y + size; i++) {
		for (int j = start_x; j < start_x + size; j++) {
			if (board[i][j] != board[start_y][start_x]) {
				bStop = false;
			}
		}
	}
	if (!bStop) {
		int r_size = size / 3;
		for (int i = start_y; i < start_y + size; i+= r_size) {
			for (int j = start_x; j < start_x + size; j += r_size) {
				go(j, i, r_size);
			}
		}
	}
	else {
		cnt_arr[board[start_y][start_x] + 1]++;
	}
}

int main() {
	int N;
	int total_cnt[3] = { 0,0,0 };

	memset(board, 0, sizeof(int) * MAX * MAX);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &board[i][j]);
			total_cnt[board[i][j] + 1]++;
		}
	}
	go(1, 1, N);			
	for (int i = 0; i < 3; i++) {
		printf("%d\n", cnt_arr[i]);
	}
	return 0;
}