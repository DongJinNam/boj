#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

ll dp[12] = { 0 };
ll dp10[12] = { 0 };

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);
	ll n, k;
	ll temp = 0, digit10 = 0;
	cin >> n >> k;

	temp = n;
	while (temp > 0) {
		temp /= 10;
		digit10++;
	}

	dp[1] = 9;
	dp10[1] = 1;
	for (int i = 2; i <= digit10; i++) {
		dp[i] = i * 9;
		dp10[i] = dp10[i - 1] * 10;
		for (int j = 0; j < i - 1; j++)
			dp[i] *= 10;
	}

	ll add = 0;
	ll ans = 0;
	for (int i = 1; i < digit10; i++)
		add += dp[i];
	add += (digit10) * (n - dp10[digit10] + 1);
	if (add < k) {
		cout << "-1\n";
		return 0;
	}
	add = 1;
	for (int i = 1; i <= digit10; i++) {
		ll beg = add;
		ll end = beg + dp[i];
		ans = 0;
		if (k >= beg && k < end) {
			ll delta = (k - beg) / i;
			ll mod = (k - beg) % i;			
			delta += dp10[i];
			for (int j = 0; j < i - mod; j++) {
				ans = delta % 10;
				delta /= 10;
			}
			break;
		}
		add += dp[i];
	}
	cout << ans << "\n";
	return 0;
}