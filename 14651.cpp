#include <stdio.h>

using namespace std;

typedef long long ll;

ll dp[33334];

// �ȴٺ��� ��õ�� �� (�ڸ� ������ �־����� 0,1,2�� ���� �� �ִ� 3�� ��� ���� ���ϱ�) (Large)
int main() {
	int i, j;
	int N;
	scanf("%d", &N);
	dp[1] = 0;
	dp[2] = 2;
	for (i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] * 3;
		dp[i] %= 1000000009;
	}
	printf("%lld\n", dp[N]);
	return 0;
}