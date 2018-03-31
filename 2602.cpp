#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[2][101][21] = { 0 };

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);

	string title, evil, angel;
	cin >> title;
	cin >> evil;
	cin >> angel;

	for (int i = 0; i < evil.length(); i++) {
		if (evil[i] == title[0]) {
			dp[0][i][1] = 1;
		}
		if (angel[i] == title[0]) {
			dp[1][i][1] = 1;
		}
	}

	// dp[0][j][n] : 문자 n개를 만족시키는 j 위치에서, 악마의 계단에서 경우의 수
	// dp[1][j][n] : 문자 n개를 만족시키는 j 위치에서, 천사의 계단에서 경우의 수
	for (int i = 1; i < title.length(); i++) {
		for (int j = 1; j < evil.length(); j++) {
			if (evil[j] == title[i]) {
				for (int k = j - 1; k >= 0; k--) {
					if (angel[k] == title[i-1]) {
						dp[0][j][i+1] += dp[1][k][i];
					}
				}
			}
			if (angel[j] == title[i]) {
				for (int k = j - 1; k >= 0; k--) {
					if (evil[k] == title[i - 1]) {
						dp[1][j][i + 1] += dp[0][k][i];
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < evil.length(); j++) {
			ans += dp[i][j][title.length()];
		}
	}
	cout << ans << "\n";
	return 0;
}