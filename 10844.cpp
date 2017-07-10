#include <stdio.h>

#define MAX 1000000000

unsigned long long dp[101][10]; // �� : �ڸ����� N�� ��, �� : ������ �ڸ���. dp[N][M] N�ڸ����� ������ �������ڸ����� M�� ��ܼ��� ����

int main() {
	int size;
	int i, j;
	unsigned long long result = 0;
	scanf("%d", &size);
	dp[1][0] = 0;
	for (i = 1; i < 10; i++)
		dp[1][i] = 1; // ���ڸ��� �� ���� ��� 1�� �ʱ�ȭ (0 ����)
	for (i = 2; i <= size; i++) {
		for (j = 0; j < 10; j++) {
			if (j > 0)
				dp[i][j] += (dp[i - 1][j - 1] % MAX);
			if (j < 9)
				dp[i][j] += (dp[i - 1][j + 1] % MAX);
		}
	}	
	for (i = 0; i < 10; i++)
		result += dp[size][i];
	result %= MAX;
	printf("%llu\n", result);
	return 0;
}