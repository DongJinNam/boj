#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>

#define MAX 400000001

int dp[401][401];

int main() {
	int N, M;
	int i, j, k;
	int from, to, add;
	int ans = MAX;
	int select;

	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			dp[i][j] = MAX;
		}
	}

	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &from, &to, &add);
		dp[from][to] = add;
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

	ans = MAX;
	for (i = 1; i <= N; i++) {
		if (dp[i][i] < ans) ans = dp[i][i];
	}
	if (ans == MAX) printf("-1\n"); // 사이클이 없는 경우
	else printf("%d\n", ans);
	return 0;
}