#include <stdio.h>

#define MAX 1001

int dp[MAX];
int arr[MAX];

int main() {
	int N;
	int max;
	int rtn = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	dp[0] = 1;
	for (int i = 1; i < N; i++) {		
		dp[i] = 1;
		max = 0;
		for (int j = i-1; j >= 0; j--) {
			if (arr[j] < arr[i]) {
				max = dp[j] > max ? dp[j] : max;
			}
		}
		dp[i] = max + 1 > 1 ? max + 1 : dp[i];
		rtn = dp[i] > rtn ? dp[i] : rtn;
	}
	printf("%d\n", rtn);
	return 0;
}