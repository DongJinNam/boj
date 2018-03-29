#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	int n;
	int ans = 0;
	std::vector<int> dp(MAX, MAX);

	dp[2] = 1;
	dp[5] = 1;

	cin >> n;
	if (n % 5 == 0) {
		cout << n / 5 << "\n";
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		if (dp[i - 2] + 1 < dp[i]) {
			dp[i] = dp[i - 2] + 1;
		}
		if (i - 5 > 0 && dp[i - 5] + 1 < dp[i]) {
			dp[i] = dp[i - 5] + 1;
		}
	}
	if (dp[n] == MAX)
		cout << -1 << "\n";
	else 
		cout << dp[n] << "\n";	
	return 0;
}