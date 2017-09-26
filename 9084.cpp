#include <stdio.h>
#include <string.h>

int dp[10001];
int coin[21];

int main() {

	int tc;
	int i, j;
	scanf("%d", &tc);

	while (tc--) {
		int cnt_coin = 0;
		int dst;

		memset(dp, 0, sizeof(int) * 10001);

		scanf("%d", &cnt_coin);

		for (i = 1; i <= cnt_coin; i++) {
			scanf("%d", &coin[i]);
		}
		scanf("%d", &dst);

		dp[0] = 1;

		for (i = 1; i <= cnt_coin; i++) {
			for (j = coin[i]; j <= dst; j++) {
				dp[j] += dp[j - coin[i]];				
			}
		}
		printf("%d\n", dp[dst]);
	}

	return 0;
}