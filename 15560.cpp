#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>

typedef long long ll;

using namespace std;

ll n, q, u, v;

ll sum(std::vector<ll> &tree, int i) {
	ll ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

void update(std::vector<ll> &tree, int i, ll diff) {
	while (i < tree.size()) {
		tree[i] += diff;
		i += (i & -i);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> q >> u >> v;
	std::vector<ll> tree(n + 1, 0);
	std::vector<ll> num(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		update(tree, i, num[i]);
	}
	while (q--) {
		ll c, a, b;
		ll ans = INT_MIN;
		cin >> c >> a >> b;
		if (c == 0) {
			for (int i = a; i <= b; i++) {
				for (int j = i; j <= b; j++) {
					ll val = sum(tree, j) - sum(tree, i - 1);
					ans = std::max(ans, u*val + v * (j - i));
				}
			}
			cout << ans << "\n";
		}
		else {
			ll diff = b - num[a];
			num[a] = b;
			update(tree, a, diff);
		}
	}
	return 0;
}