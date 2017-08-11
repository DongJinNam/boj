#include <iostream>

using namespace std;

typedef long long ll;

ll dp[120];

int main() {
	std::ios::sync_with_stdio(false);
	int N, i;
	cin >> N;
	dp[1] = dp[2] = dp[3] = 1;
	for (i = 4; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 3];
	}
	cout << dp[N];
	return 0;
}