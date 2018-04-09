#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);

	int a, b, n;
	cin >> a >> b >> n;

	int rem = a % b;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (rem * 10) / b;
		rem = (rem * 10) % b;
	}
	cout << ans << "\n";
	return 0;
}