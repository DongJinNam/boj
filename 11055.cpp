#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX 1001
int arr[1001];
int dp[1001];

int main() {

	int N;
	int max = INT_MIN;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	dp[0] = arr[0];
	max = arr[0];
	for (int i = 1; i < N; i++) {
		dp[i] = arr[i];
		for (int j = i-1; j >= 0; j--) {
			if (arr[j] < arr[i]) {
				dp[i] = dp[j] + arr[i] > dp[i] ? dp[j] +arr[i] : dp[i];
			}
		}
		max = dp[i] > max ? dp[i] : max;
	}
	printf("%d\n", max);
	return 0;
}