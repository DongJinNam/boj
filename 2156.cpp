#include <stdio.h>
#include <algorithm>

int dp[10001];
int arr[10001];

int main() {
	int N;
	int i, j, k, data;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) 
		scanf("%d", &arr[i]);

	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (i = 3; i <= N; i++) {
		dp[i] = dp[i - 1];
		if (dp[i] < dp[i - 2] + arr[i]) // 두개 전 잔하고 이번잔 마신것이 바로 이전 최대 마신양보다 클 시에
			dp[i] = dp[i - 2] + arr[i];
		if (dp[i] < dp[i - 3] + arr[i - 1] + arr[i]) { // 이전 잔하고 이번 잔 마신것이 더 클 시에
			dp[i] = dp[i - 3] + arr[i - 1] + arr[i];
		}
	}
	printf("%d\n", dp[N]);	
	return 0;
}