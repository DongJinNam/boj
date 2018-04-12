#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		int h, w, n, ans = 0;
		cin >> h >> w >> n;

		if (n % h == 0) {
			ans += h * 100;
			ans += (n / h);
		}
		else {
			ans += (n % h) * 100;
			ans += ((n / h) + 1);
		}		
		cout << ans << "\n";
	}
	return 0;
}