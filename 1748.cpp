#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	int n;
	int temp, i, j;
	int digit = 0;
	int ans = 0;
	cin >> n;

	temp = n;
	while (temp > 0) {
		temp /= 10;
		digit++;
	}
	if (digit == 1) {
		ans = n;
	}
	else {
		ans = 9;
		for (i = 1; i < digit - 1; i++) {
			ans += (std::pow(10, i+1) - std::pow(10, i)) * (i+1);
		}
		ans += (n - std::pow(10, digit - 1) + 1) * digit;
	}
	cout << ans;
	return 0;
}