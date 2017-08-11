#include <stdio.h>
#include <map>

int t_arr[30];
int p_arr[30];
int dp[30];

int main() {
	int N, max = 0;
	int i, j, k;
	int sum = 0;

	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d %d", &t_arr[i], &p_arr[i]);
	}	
	for (i = 1; i <= N; i++) {
		dp[i] = dp[i - 1] > dp[i] ? dp[i - 1] : dp[i];
		if ((i + (t_arr[i] - 1)) <= N && dp[i + (t_arr[i] - 1)] < dp[i - 1] + p_arr[i]) {
			dp[i + (t_arr[i] - 1)] = dp[i - 1] + p_arr[i];
			max = dp[i - 1] + p_arr[i] > max ? dp[i - 1] + p_arr[i] : max;
		}
	}
	printf("%d", max);
	return 0;
}