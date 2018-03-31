#include <iostream>
#include <vector>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	int max = 0;
	cin >> n;

	std::vector<int> box_vec(n, 0);
	std::vector<int> dp(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> box_vec[i];
	}

	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (box_vec[j] < box_vec[i]) {
				dp[i] = dp[j] + 1 > dp[i] ? dp[j] + 1 : dp[i];
			}
			else if (box_vec[j] == box_vec[i]) {
				dp[i] = dp[j] > dp[i] ? dp[j] : dp[i];
			}
		}
		if (dp[i] == 0) dp[i] = 1;
	}
	for (int i = 0; i < n; i++)
		max = dp[i] > max ? dp[i] : max;
	cout << max << "\n";
	return 0;
}