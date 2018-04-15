#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, b, c;
std::vector<ll> a;

int main() {
	scanf("%lld", &n);
	a.resize(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	scanf("%lld %lld", &b, &c);

	ll ans = n;
	for (int i = 0; i < n; i++) {
		a[i] = a[i] - b < 0 ? 0 : a[i] - b;
		if (a[i] > 0) {
			ans += a[i] / c;
			if (a[i] % c != 0) ans++;
		}
	}
	printf("%lld\n", ans);

	return 0;
}