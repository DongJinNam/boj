#include <iostream>

using namespace std;

#define MAX 1000001
#define MOD 15746

int dp[MAX][2] = { 0 };

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;
	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[2][0] = 1;
	dp[2][1] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i][0] = ((dp[i - 2][0] % MOD) + (dp[i-2][1] % MOD)) % MOD;
		dp[i][1] = ((dp[i - 1][0] % MOD) + (dp[i - 1][1] % MOD)) % MOD;
	}
	cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
	return 0;
}