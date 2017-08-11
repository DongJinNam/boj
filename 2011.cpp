#include <iostream>
#include <string>
#include <algorithm>

#define MAX 1000000

using namespace std;

int dp[5001];

int main() {

	std::ios::sync_with_stdio(false);
	string s;
	int i, j;
	cin >> s;

	dp[0] = 1;
	for (i = 0; i < s.length(); i++) {
		int at = (int)s[i] - '0';
		if (i == 0) {
			if (at > 0) dp[i+1] = 1;
			else dp[i + 1] = 0;
			continue;
		}
		int prev = (int)s[i - 1] - '0';
		int comp = prev * 10 + at;
		if (at > 0) {
			dp[i + 1] += dp[i];
			dp[i + 1] %= MAX;
		}
		if (comp >= 10 && comp <= 26) {
			dp[i + 1] += dp[i - 1];
			dp[i + 1] %= MAX;
		}
	}
	cout << dp[s.length()];
	return 0;
}