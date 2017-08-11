#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int H, M;
	int ans, ans_h, ans_m;
	cin >> H >> M;

	ans = H * 60 + M - 45;

	if (ans < 0) {
		ans = 60 * 24 + ans;
	}
	ans_h = ans / 60;
	ans_m = ans % 60;
	cout << ans_h << " " << ans_m;
	return 0;
}