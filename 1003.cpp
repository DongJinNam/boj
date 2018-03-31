#include <iostream>
#include <vector>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);

	std::vector<std::vector<int>> dp(41, std::vector<int>(2, 0));
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;	
	for (int i = 2; i <= 40; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		cout << dp[n][0] << " " << dp[n][1] << "\n";
	}
	return 0;
}