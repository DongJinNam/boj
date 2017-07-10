#include <stdio.h>

#define MAX 10007 // ���� ������

unsigned long long dp[1001][10]; // �� : �ڸ����� N�� ��, �� : ������ �ڸ���. dp[N][M] N�ڸ����� ������ �������ڸ����� M�� ���������� ����
unsigned long long sum[1001][10]; // dp[N][M] N�ڸ����� ������ ������ �ڸ��� 0 ~ M���� �������� ���� ����

int main() {
	int size;
	int i, j, k;
	unsigned long long result = 0;
	scanf("%d", &size);
	sum[1][0] = 1;
	dp[1][0] = 1;
	for (i = 1; i < 10; i++) {
		dp[1][i] = 1; // ���ڸ��� �� ���� ��� 1�� �ʱ�ȭ (0 ����)		
		sum[1][i] += (sum[1][i - 1] + dp[1][i]);
	}
	for (i = 2; i <= size; i++) {
		sum[i][0] += (sum[i - 1][0] % MAX);
		dp[i][0] = (dp[i - 1][0] % MAX);
		for (j = 1; j < 10; j++) {
			dp[i][j] = (sum[i - 1][j] % MAX);
			sum[i][j] = ((sum[i][j - 1] + dp[i][j]) % MAX);
		}
	}
	printf("%llu\n", sum[size][9]);
	return 0;
}