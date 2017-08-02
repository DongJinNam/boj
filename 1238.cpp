#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

typedef std::pair<int, int> iPair;

int inf = 100000001;
int dp[1001][1001];

int main() {
	int N, M, X;
	int i, j, k;
	int from, to, add;
	int max = 0, temp;

	scanf("%d %d %d", &N, &M, &X);

	// inf 초기화
	for (i = 1; i <= N; i++) 
		fill(dp[i], dp[i] + N + 1, inf);
	// inf 초기화
	for (i = 1; i <= N; i++)
		dp[i][i] = 0;

	while (M--) {
		scanf("%d %d %d", &from, &to, &add);
		dp[from][to] = add;
	}
	// floyd warshall
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
		temp = dp[i][X] + dp[X][i];
		max = std::max(temp, max);
	}
	printf("%d", max);
	return 0;
}