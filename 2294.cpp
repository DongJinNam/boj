#include <iostream>
#include <vector>

using namespace std;

int inf = 1000000000;

int main() {
	std::ios::sync_with_stdio(false);

	int n, k, i, j;
	std::vector<int> num_arr;
	std::vector<int> dp;
	cin >> n >> k;

	num_arr.resize(n, 0);
	dp.resize(k+1, inf);
	for (i = 0; i < n; i++)
		cin >> num_arr[i];

	dp[0] = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j <= k; j++) {
			if (j - num_arr[i] >= 0 && dp[j - num_arr[i]] + 1 < dp[j]) {
				dp[j] = dp[j - num_arr[i]] + 1;
			}
		}
	}
	if (dp[k] == inf) cout << -1;
	else cout << dp[k];
	return 0;
}