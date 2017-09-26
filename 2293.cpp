#include <iostream>
#include <vector>

using namespace std;

int dp[10001];

int main() {
	std::ios::sync_with_stdio(false);

	int n, k, i, j;
	std::vector<int> num_arr;
	cin >> n >> k;

	num_arr.resize(n, 0);
	for (i = 0; i < n; i++)
		cin >> num_arr[i];

	dp[0] = 1;
	for (i = 0; i < n; i++) {
		for (j = 0; j <= k; j++) {
			if (j - num_arr[i] >= 0) {
				dp[j] += dp[j - num_arr[i]];
			}
		}
	}
	cout << dp[k];
	return 0;
}