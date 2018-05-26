#include <iostream>
#include <vector>

using namespace std;

int dp[41] = { 0 };
bool bFix[41] = { false };

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	// dp(input n <= 40)
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < 41; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	int n, m, ans = 1, count = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int pos;
		cin >> pos;
		bFix[pos] = true;
	}
	// 구간별 곱하기 계산
	for (int i = 1; i <= n; i++) {
		if (bFix[i]) {
			ans *= dp[count];
			count = 0;
		}
		else {
			count++;
		}
	}
	ans *= dp[count];
	cout << ans << "\n";
	return 0;
}