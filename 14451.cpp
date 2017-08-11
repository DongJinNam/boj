#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int n, m, i;
	int ans = 1;	
	cin >> n >> m;

	std::vector<int> arr(n + 1, 0);
	if (n == 0) {
		cout << 1 % m; // ÁÖÀÇ
		return 0;
	}

	for (i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] == 0) ans *= 1;
		else ans *= arr[i];
		ans %= m;
	}
	cout << ans;
	return 0;
}