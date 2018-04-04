#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000001

typedef long long ll;

std::vector<ll> dp(MAX, 0);

ll recur(ll n, ll p, ll q) {
	if (n == 0)
		return 1;
	ll ans1, ans2;
	if (n / p < MAX && dp[n / p] != 0)
		ans1 = dp[n / p];
	else {
		ans1 = recur(n / p, p, q);
		if (n / p < MAX) dp[n / p] = ans1;
	}
	if (n / q < MAX && dp[n / q] != 0) {
		ans2 = dp[n / q];
	}
	else {
		ans2 = recur(n / q, p, q);
		if (n / q < MAX) dp[n / q] = ans2;
	}
	return ans1 + ans2;
}

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);
	ll n, p, q;
	cin >> n >> p >> q;
	
	ll ans = recur(n, p, q);
	cout << ans;
	return 0;
}