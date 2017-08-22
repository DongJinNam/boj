#include <iostream>
#include <string>
#include <vector>
using namespace std;

int inf = 1000000000;

int main() {
	std::ios::sync_with_stdio(false);
	int n, i, j;
	string s;
	cin >> n;
	cin >> s;

	vector<int> dp(n + 1, inf);
	dp[0] = 0;
	for (i = 1; i < n; i++) {
		for (j = i - 1; j >= 0; j--) {
			if (s[i] != s[j]) {
				if (s[i] == 'B' && s[j] == 'J') {
					if (dp[i] > dp[j] + (i - j) * (i - j)) dp[i] = dp[j] + (i - j) * (i - j);
				}
				else if (s[i] == 'J' && s[j] == 'O') {
					if (dp[i] > dp[j] + (i - j) * (i - j)) dp[i] = dp[j] + (i - j) * (i - j);
				}
				else if (s[i] == 'O' && s[j] == 'B') {
					if (dp[i] > dp[j] + (i - j) * (i - j)) dp[i] = dp[j] + (i - j) * (i - j);
				}
			}
		}
	}
	if (dp[n - 1] == inf) cout << -1;
	else cout << dp[n - 1];
	return 0;
}