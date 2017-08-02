#include <stdio.h>
#include <math.h>

using namespace std;

int dp[5001];

int main() {
	int N;
	int i, j;
	int select;
	int ans, ans2; // 답 분자, 답 분모
	int prev; // 이전 dp값
	int first = 0, second = 0; // 분자, 분모
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
		// 짝수
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
		// 홀수
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