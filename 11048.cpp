#include <stdio.h>
#include <algorithm>
#include <string.h>

int board[1001][1001];
int dp[1001][1001];

int yy[3] = { 0, 1, 1 };
int xx[3] = { 1,1, 0 };

int main() {

	int N, M;
	int i, j, k;
	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	dp[1][1] = board[1][1];

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			for (k = 0; k < 3; k++) {
				int n_y = i + yy[k];
				int n_x = j + xx[k];
				if (n_y <= N && n_x <= M)
					dp[n_y][n_x] = dp[i][j] + board[n_y][n_x] > dp[n_y][n_x] ? dp[i][j] + board[n_y][n_x] : dp[n_y][n_x];
			}
		}
	}

	printf("%d", dp[N][M]);
	return 0;
}