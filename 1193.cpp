#include <stdio.h>
#include <math.h>

using namespace std;

int dp[5001];

int main() {
	int N;
	int i, j;
	int select;
	int ans, ans2; // �� ����, �� �и�
	int prev; // ���� dp��
	int first = 0, second = 0; // ����, �и�
	scanf("%d", &N);

	dp[1] = 1;
	select = 1;
	for (i = 2; i <= 5000; i++) {
		dp[i] = i * (i + 1) / 2;
		if (dp[i - 1] < N && N <= dp[i]) {
			select = i;
			break;
		}
	}

	if (select % 2 == 0) {
		// ¦��
		int prev = dp[select - 1];
		int first = 0, second = select + 1;
		for (i = prev + 1; i <= N; i++) {
			first++;
			second--;
		}
		ans = first;
		ans2 = second;
	}
	else {
		// Ȧ��
		int prev = dp[select - 1];
		int first = select + 1, second = 0;
		for (i = prev + 1; i <= N; i++) {
			first--;
			second++;
		}
		ans = first;
		ans2 = second;
	}
	printf("%d/%d", ans, ans2);
	return 0;
}