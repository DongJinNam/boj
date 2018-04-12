#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

typedef long long ll;

int n;
int k;

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);
	
	cin >> n >> k;

	int left = 1, right = k, mid;
	int ans;
	while (left <= right) {
		ll cnt = 0;
		int mid = (left + right) / 2;
		for (int i = 1; i <= n; i++)
			cnt += std::min(mid / i, n);
		if (cnt < k) left = mid + 1;
		else {
			ans = mid;
			right = mid - 1;
		}
	}
	cout << ans << "\n";
	return 0;
}