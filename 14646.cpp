#include <stdio.h>
#include <vector>

bool check[100001];
int dp[200001];

int main() {

	int N;
	int i, j;
	int ans = 0;
	scanf("%d", &N);

	std::vector<int> arr(N * 2 +1, 0);
	for (i = 1; i <= N * 2; i++)
		scanf("%d", &arr[i]);	
	for (i = 1; i <= N * 2; i++) {
		if (check[arr[i]]) {
			check[arr[i]] = false;
			dp[i] = dp[i - 1] - 1;
		}
		else {
			check[arr[i]] = true;
			dp[i] = dp[i - 1] + 1;
		}
		ans = dp[i] > ans ? dp[i] : ans;
	}
	printf("%d\n", ans);
	return 0;
}