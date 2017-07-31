#include <stdio.h>

int before[51][51];
int after[51][51];

void turn_up(int i, int j) {
	int a, b;
	for (a = i; a < i + 3; a++) {
		for (b = j; b < j + 3; b++) {
			before[a][b] = 1 - before[a][b];
		}
	}
}

int main() {

	int N, M;
	int i, j,a,b;
	int ans = 0;
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%1d", &before[i][j]);
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%1d", &after[i][j]);
		}
	}
	// greedy algorithm
	for (i = 0; i <= N - 3; i++) {
		for (j = 0; j <= M - 3; j++) {
			int s_i = i, s_j = j;
			if (before[s_i][s_j] != after[s_i][s_j]) {
				turn_up(i, j);
				ans++;
			}
		}
	}

	bool bCorrect = true;
	for (i = 0; i < N; i++) {
		if (!bCorrect) break;
		for (j = 0; j < M; j++) {
			if (before[i][j] != after[i][j]) {
				bCorrect = false;
				break;
			}
		}
	}
	if (bCorrect) printf("%d", ans);
	else printf("-1", ans);
	return 0;
}