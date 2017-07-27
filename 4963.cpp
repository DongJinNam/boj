#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 51

int board[MAX][MAX];
bool check[MAX][MAX];
int w, h;

int dfs(int y, int x) {

	check[y][x] = true;

	int start_y, start_x, end_y, end_x;
	int ans = 1;

	start_x = x - 1;
	end_x = x + 1;
	start_y = y - 1;
	end_y = y + 1;
	
	if (start_x < 0) start_x = 0;
	if (start_y < 0) start_y = 0;
	if (end_x >= w) end_x = w-1;
	if (start_y >= h) end_y = h-1;

	for (int i = start_y; i <= end_y; i++) {
		for (int j = start_x; j <= end_x; j++) {
			if (board[i][j] && check[i][j] == false) {
				ans += dfs(i, j);
			}
		}
	}
	return ans;
}

int main() {

	int data, data2;
	int i, j;

	while (1) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) break;

		memset(board, 0, sizeof(int)*MAX*MAX);
		int cnt = 0;
		int total = 0;
		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				scanf("%d", &board[i][j]);
				check[i][j] = false;
				if (board[i][j] == 1) {
					cnt++;
				}
			}
		}
		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				if (board[i][j] == 1 && check[i][j] == false) {
					cnt -= dfs(i, j);
					total++;
				}
			}
		}
		printf("%d\n", total);
	}
	return 0;
}