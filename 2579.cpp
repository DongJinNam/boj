#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 301

int arr[MAX];
int dp[MAX][3];

int main() {

	int N;
	int i, j, k;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &arr[i+1]);

	dp[1][1] = arr[1];
	dp[2][1] = arr[2];
	dp[2][2] = arr[1] + arr[2];
	for (i = 3; i <= N; i++) {
		if (dp[i - 2][1] > dp[i - 2][2]) 
			dp[i][1] = dp[i - 2][1] + arr[i];		
		else
			dp[i][1] = dp[i - 2][2] + arr[i];
		dp[i][2] = dp[i - 1][1] + arr[i];
	}
	printf("%d\n", dp[N][1] > dp[N][2] ? dp[N][1] : dp[N][2]);
	return 0;
}