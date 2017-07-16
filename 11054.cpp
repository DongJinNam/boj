#include <stdio.h>
#include <string.h>

#define MAX 1001

int dp[MAX]; // �����ϴ� �κм��� dp
int dp2[MAX]; // �����ϴ� �κм��� dp
int arr[MAX];

int main() {

	int N;
	int max = 0; // ���� �� ������� �κм��� ����
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	// ���� �� �����ϴ� �κм��� ���ϱ�
	dp[0] = 1;
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	dp2[N - 1] = 1;
	// ���� �� �����ϴ� �κм���
	for (int i = N - 1; i >= 0; i--) {
		dp2[i] = 1;
		for (int j = i + 1; j < N; j++) {
			if (arr[j] < arr[i] && dp2[i] < dp2[j] + 1) {
				dp2[i] = dp2[j] + 1;
			}
		}
	}

	max = 0;
	for (int i = 0; i < N; i++)  // ���� �� ������� �κм��� ���� ���ϱ�
		max = (dp[i] + dp2[i] - 1) > max ? (dp[i] + dp2[i] - 1) : max;
	printf("%d\n", max);
	return 0;
}