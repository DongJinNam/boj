#include <stdio.h>
#include <string.h>

#define MAX 1001

int dp[MAX];
int arr[MAX];

int main() {

	int N;
	int max = 0; // ���� �� �����ϴ� �κм��� ����
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	
	dp[N - 1] = 1;
	max = 1;
	// ���� �� �����ϴ� �κм��� ���̸� �Ųٷ�
	for (int i = N - 1; i >= 0; i--) {
		dp[i] = 1;
		for (int j = i + 1; j < N; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		max = dp[i] > max ? dp[i] : max;
	}
	printf("%d\n", max);
	return 0;
}