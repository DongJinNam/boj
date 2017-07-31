#include <stdio.h>

int dp[101][101];
int ans[101];
int inf = 2001;

int main() {

	int N, M;
	int i, j, k, from, to;
	scanf("%d", &N);
	scanf("%d", &M);

	for (i = 0; i < M; i++) {
		scanf("%d %d", &from, &to);
		dp[from][to] = 1;
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (i == j) dp[i][j] = 0;
			else dp[i][j] = dp[i][j] > 0 ? dp[i][j] : inf;			
		}
	}

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
		for (j = 1; j <= N; j++) {
			if (dp[i][j] == inf && dp[j][i] == inf) ans[i]++;
		}
		printf("%d\n", ans[i]);
	}	
	return 0;
}