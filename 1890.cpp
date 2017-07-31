#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int board[101][101];
long long dp[101][101];
int N;

bool pos_check(int y, int x) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

int main() {
	// jump
	int i, j;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	dp[0][0] = 1;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (i == N - 1 && j == N - 1) break;
			// 오른쪽
			if (pos_check(i, j + board[i][j])) {
				dp[i][j + board[i][j]] += (long long) dp[i][j];
			}
			// 아래
			if (pos_check(i + board[i][j], j)) {
				dp[i + board[i][j]][j] += (long long) dp[i][j];
			}
		}
	}
	printf("%lld", dp[N - 1][N - 1]);
	return 0;
}