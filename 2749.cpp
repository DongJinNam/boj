#include <stdio.h>

const int limit = 1000000;
const int len = limit / 10 * 15;

long long dp[len];

int main() {
	long long N;
	scanf("%lld", &N);
	dp[0] = 0;
	dp[1] = 1;
	// �Ǻ���ġ DP�� Ǯ�� (�ٸ� N�� 10^18 �������� ����)
	// �ǻ�� �ֱ�
	// ��Ģ�� ã��. 0~15 �������� �Ǻ���ġ ���� 3���� ���� �������� ���� �� ������ �ݺ��ȴ�.
	for (int i = 2; i < len; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= limit;
	}
	printf("%lld\n", dp[N % len]);
	return 0;
}