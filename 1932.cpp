#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
typedef std::pair<int, int> iPair;

int tri[501][501];
int dp[501][501];
int N;
int main() {	
	int i, j;
	int max = 0;
	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= i; j++) {
			scanf("%d", &tri[i][j]);
		}
	}

	dp[1][1] = tri[1][1];
	for (i = 2; i <= N; i++) {
		for (j = 1; j <= i; j++) {
			int comp1 = 0, comp2 = 0;
			if (j - 1 > 0) comp1 = dp[i - 1][j - 1];
			if (j < i) comp2 = dp[i - 1][j];

			dp[i][j] = tri[i][j];
			if (comp1 > comp2) {
				dp[i][j] += comp1;
			}
			else {
				dp[i][j] += comp2;
			}
			max = dp[i][j] > max ? dp[i][j] : max;
		}
	}
	printf("%d", max);
	return 0;
}