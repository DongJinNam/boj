#include <stdio.h>
#include <string.h>

#define MAX 101
#define LIMIT 100001

int dp[MAX][MAX]; // i -> j 까지 최소 비용
int next[MAX][MAX]; // i -> j 까지 경로 중 가장 앞에 있는 위치

// 플로이드 워셜 알고리즘

int main() {

	int N, M;
	int from, to, add;
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = LIMIT;
		}
	}

	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d", &from, &to, &add);
		next[from][to] = to;

		if (dp[from][to] == LIMIT) dp[from][to] = add;
		else {
			if (dp[from][to] > add)
				dp[from][to] = add;
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) dp[i][j] = 0;
				if (dp[i][j] > dp[i][k] + dp[k][j]) {
					dp[i][j] = dp[i][k] + dp[k][j];
					next[i][j] = next[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	return 0;
}