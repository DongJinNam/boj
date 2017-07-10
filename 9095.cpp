#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int dp[11];

int main() 
{
	int tc, data, i;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &data);
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (i = 4; i <= data; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		printf("%d\n", dp[data]);
	}
	return 0;
}