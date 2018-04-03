#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);

	ll n;
	ll num = 1;
	ll count = 1;
	ll digit = 9;
	ll from = 1;
	ll to = digit * count + 1;
	int ans = -1;
	cin >> n;

	// 범위를 먼저 구한 후, 그 다음 공식을 이용하여 계산한다.
	for (int i = 1; i <= 8; i++) {
		if (from <= n && n < to) {
			ll rem = (n - (from - 1)) % i;
			ll div = (n - (from - 1)) / i;			
			if (rem == 0) div--;
			num += div;
			from = (from - 1) + (div * i) + 1;
			to = from + i;
			for (ll j = to-1; j >= from; j--) {
				if (j == n) {
					ans = num % 10;
					num /= 10;
					break;
				}
				num /= 10;
			}
			if (ans != -1) break;
		}
		else {
			num *= 10;
			digit *= 10;
			count++;
			from = to;
			to = to + digit * count;
		}
	}
	cout << ans << "\n";
	return 0;
}