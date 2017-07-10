#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

int arr[100001][2];
int dp[100001][3]; // 0 : i��°���� ��ƼĿ �ȶ��� �� �ִ� ����, 1 : i��°���� �� ��ƼĿ ������ �ִ� ����, 2 : i��°���� �Ʒ� ��ƼĿ ���� �� �ִ� ����

int main() {

	int tc;
	int i, j, k;
	int N;
	int max;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &N);
		for (i = 1; i <= N; i++)
			scanf("%d", &arr[i][0]);
		for (i = 1; i <= N; i++)
			scanf("%d", &arr[i][1]);
		dp[1][0] = 0;
		dp[1][1] = arr[1][0];
		dp[1][2] = arr[1][1];
		for (i = 2; i <= N; i++) {
			max = dp[i - 1][0] > dp[i - 1][1] ? dp[i - 1][0] : dp[i - 1][1];
			max = dp[i - 1][2] > max ? dp[i - 1][2] : max;
			dp[i][0] = max;
			dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][2]) + arr[i][0];
			dp[i][2] = std::max(dp[i - 1][0], dp[i - 1][1]) + arr[i][1];
		}

		max = dp[N][0] > dp[N][1] ? dp[N][0] : dp[N][1];
		max = dp[N][2] > max ? dp[N][2] : max;
		printf("%d\n", max);
	}
	return 0;
}