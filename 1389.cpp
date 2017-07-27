#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>

#define MAX 10000001

int dp[101][101];
int next[101][101];

int main() {
	int N, M;
	int i, j, k;
	int from, to;
	int ans = MAX;
	int select;

	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (i == j) dp[i][j] = 0;
			else dp[i][j] = MAX;
		}
	}

	for (i = 0; i < M; i++) {
		scanf("%d %d", &from, &to);
		dp[from][to] = 1;
		dp[to][from] = 1;
	}
	// 플로이드
	for (k = 1; k <= N; k++) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				if (dp[i][j] > dp[i][k] + dp[k][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
	}

	for (i = 1; i <= N; i++) {
		int total = 0;
		for (j = 1; j <= N; j++) {
			total += dp[i][j];
		}
		if (total < ans) {
			ans = total;
			select = i;
		}
	}
	printf("%d\n", select);
	return 0;
}